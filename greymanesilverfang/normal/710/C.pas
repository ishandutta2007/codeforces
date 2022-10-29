program Project710C;
uses math;
var odd, even, n, mid, i, j: integer;
procedure writeodd;
begin
write(odd, ' ');
inc(odd, 2);
end;
procedure writeeven;
begin
write(even, ' ');
inc(even, 2);
end;
begin
odd := 1;
even := 2;
read(n);
mid := n div 2 + 1;
for i := 1 to n do
  begin
  for j := 1 to n do if min(abs(i - mid), abs(j - mid)) mod 2 = 0 then writeodd else writeeven;
  writeln;
  end;
end.