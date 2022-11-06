var
  n,k,x,y,ans:int64;
  i:longint;
begin
  readln(n,k);ans:=-maxlongint;
  for i:=1 to n do begin
    readln(x,y);
    if y>k then dec(x,y-k);
    if x>ans then ans:=x;
  end;
  writeln(ans);
end.