var a: longint;
begin
readln(a);
if a=sqr(trunc(sqrt(a))) then writeln(trunc(sqrt(a))*2)
else if a-sqr(trunc(sqrt(a)))<=trunc(sqrt(a)) then writeln(trunc(sqrt(a))*2+1)
else writeln(trunc(sqrt(a))*2+2);
end.