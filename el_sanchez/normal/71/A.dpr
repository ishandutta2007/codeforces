var
i, n: longint;
s: string;

begin
readln(n);
for i := 1 to n do begin
readln(s);
if length(s) <= 10 then
writeln(s)
else
writeln(s[1], length(s)-2, s[length(s)]);
end;
i := i;

end.