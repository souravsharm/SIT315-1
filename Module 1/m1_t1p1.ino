// Variables
int cm = 0;
int LED = 10;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  // Measure the distance in Centimeter
  cm = 0.01723 * readUltrasonicDistance(7, 7);
 
  // Prints the current range
  Serial.print(cm);
  Serial.println("cm");
  
  
  if (cm <= 50)
  {
  	digitalWrite(LED, HIGH);
  }
  
  else
  {
    
  	digitalWrite(LED, LOW);
  }
  delay(100); 
}
