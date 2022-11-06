program guzirobot;
var
x1,y1,x2,y2:int64;
max:int64;

begin
 readln(x1,y1);
 readln(x2,y2);
 if abs(x1-x2) > abs(y1-y2) then
  max:=abs(x1-x2)
 else
  max:=abs(y1-y2);
 writeln(max);
end.