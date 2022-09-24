var 
n,m:int64;
i,ans:longint;
begin
readln(n,m);
ans:=1;
for i:=1 to n do
begin
if ((m mod 2) = 0) then 
begin
inc(ans);
m := m div 2;
end;
end;
writeln(ans);
end.