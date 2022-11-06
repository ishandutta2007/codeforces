var
  n,s,i,x,y,ans:longint;
begin
  readln(n,s);ans:=-1;
  for i:=1 to n do begin
    readln(x,y);
    if y>0 then inc(x) else y:=100;
    if (x<=s)and(100-y>ans) then ans:=100-y;
  end;
  writeln(ans);
end.