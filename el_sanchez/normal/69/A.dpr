var
    i, x, y, z, a, b, c: longint;
   n: longint;
begin
read(n); 
x := 0;
y := 0;
z := 0; 
for i := 1 to n do begin
    read(a, b, c);
    x := x + a;
    y := y + b;
    z := z + c;  
end;
if (x=0) and (y=0) and (z=0) then write('YES') else write('NO');
end.