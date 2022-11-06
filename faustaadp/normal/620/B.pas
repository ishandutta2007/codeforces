program se7vensegment;
var
a,b,j:longint;
i:longint;
has:longint;
temp:longint;
hass:longint;
sgm:array[0..9]of longint=(6,2,5,5,4,5,6,3,7,6);



begin
 readln(a,b);
 for i:=a to b do begin
  j:=i;
  hass:=0;
   while j div 10 > 0 do begin
    temp:=j mod 10;
    hass:=hass+sgm[temp];
    j:=j div 10;
   end;
  hass:=hass+sgm[j mod 10];
  has:=has+hass;
 end;
 writeln(has);
end.