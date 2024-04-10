var nod,i,x1,y1,a,b,x,y,k1,k2: int64;
begin
readln (a,b,x,y);
x1:=x;
y1:=y;
    repeat
    if x > y then
    x := x mod y
    else
    y := y mod x;
    until (x = 0) or (y = 0);
    nod := x + y;
x:=x1 div nod;
y:=y1 div nod;
k1:=a div x;
k2:=b div y;
if k1>k2 then writeln (k2) else writeln (k1);
end.