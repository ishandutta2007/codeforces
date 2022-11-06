var n,i,x,y,ans:longint;
begin
  readln(n);
  for i:=1 to n do begin
    readln(x,y);
    if y-x>1 then inc(ans);
  end;
  writeln(ans);
end.