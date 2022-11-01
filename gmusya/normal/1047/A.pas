var a,b,c,n: longint;
begin
readln (n);
a:=1;
if (n mod 3 = 0) or (n mod 3 = 1) then b:=1;
if (n mod 3 = 2) then b:=2; 
c:=n-a-b;
writeln (a, ' ', b, ' ', c);
end.