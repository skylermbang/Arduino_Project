

const int TriggerPin = 8; //Trig pin
const int EchoPin = 9; //Echo pin
long Duration = 0;
int sensorPin = A0; // select the input pin for the potentiometer
int ledPin = 13; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor
 
void setup(){
pinMode(TriggerPin,OUTPUT); // Trigger is an output pin
pinMode(EchoPin,INPUT); // Echo is an input pin
pinMode (ledPin, OUTPUT);
Serial.begin(9600); // Serial Output
Serial.println("Date & Time, Distance, Sound");
}

void loop(){
  
digitalWrite(TriggerPin, LOW);
delayMicroseconds(2);
digitalWrite(TriggerPin, HIGH); // Trigger pin to HIGH
delayMicroseconds(10); // 10us high
digitalWrite(TriggerPin, LOW); // Trigger pin to HIGH

Duration = pulseIn(EchoPin,HIGH); // Waits for the echo pin to get high
// returns the Duration in microseconds
long Distance_mm = Distance(Duration); // Use function to calculate the distance


sensorValue = analogRead (sensorPin);
digitalWrite (ledPin, HIGH);
//delay (sensorValue);
digitalWrite (ledPin, LOW);
//delay (sensorValue);
//delayMicroseconds(10000);



Serial.print(",");
Serial.print(Distance_mm);
Serial.print(",");
Serial.println(sensorValue,DEC);
//Serial.println(" mm");

//delay(0.00001); // Wait to do next measurement
}

long Distance(long time)
{
// Calculates the Distance in mm
// ((time)*(Speed of sound))/ toward and backward of object) * 10

long DistanceCalc; // Calculation variable
DistanceCalc = ((time /2.9) / 2); // Actual calculation in mm
//DistanceCalc = time / 74 / 2; // Actual calculation in inches
return DistanceCalc; // return calculated value

}
