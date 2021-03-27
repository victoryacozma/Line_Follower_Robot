  int vSpeed = 255;        // MAX 255
  int turn_speed = 230;    // MAX 255 
  int turn_delay = 10;
  
//L293 Connection   
  const int motorB1      = 12; 
  const int motorB2      = 13; 
  const int motorBspeed  = 11;

//Sensor Connection
  const int left_sensor_pin =A0;
  const int right_sensor_pin =A1;  
  
  int left_sensor_state;
  int right_sensor_state;

void setup() {
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);

  delay(3000);
  
}

void loop() {
  
left_sensor_state = analogRead(left_sensor_pin);
right_sensor_state = analogRead(right_sensor_pin);

Serial.println(left_sensor_state);

if(right_sensor_state > 500 && left_sensor_state < 500)
{
  Serial.println("turning right");
                        
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  analogWrite (motorBspeed, turn_speed);
  
  }
if(right_sensor_state < 500 && left_sensor_state > 500)
{
  Serial.println("turning left");
                      
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  }

if(right_sensor_state < 500 && left_sensor_state < 500)
{
  Serial.println("stop");                    
  analogWrite (motorBspeed, 0);
  
  }

if(right_sensor_state > 500 && left_sensor_state > 500)
{ 
   Serial.println("forward");
   analogWrite (motorBspeed, vSpeed);
  
  }

 
}
 
