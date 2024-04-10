var
  n,m,i,x,ans:longint;
begin
  readln(n,m);
  for i:=1 to n do begin
    read(x);if x+m<=5 then inc(ans);
  end;
  writeln(ans div 3);
end.