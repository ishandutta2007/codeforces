var
 a, b, c: int64;

begin
readln(a, b);
c := 0;
while b > 0 do
begin
 c := c * 10 + b mod 10;
b := b div 10;
end;
writeln(a + c);
end.