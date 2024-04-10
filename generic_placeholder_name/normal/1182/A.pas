var n: integer;
        ans: int64;
begin
readln(n);
if n mod 2 <> 0 then ans:=0 else ans:=1<<(n div 2);
writeln(ans);
end.