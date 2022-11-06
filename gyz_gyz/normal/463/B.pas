var
  n,i,x,ans:longint;
begin
  readln(n);
  for i:=1 to n do begin
    read(x);
    if x>ans then ans:=x;
  end;
  writeln(ans);
end.