program elephant;
var
x:longint;

begin
 readln(x);
 if x mod 5 = 0 then
  writeln(x div 5)
 else
  writeln(x div 5+1);
end.