var n,x,y,a,i,ans:longint;
begin
  readln(n);
  for i:=1 to n do begin
    readln(x,y);dec(a,x);inc(a,y);
    if a>ans then ans:=a;
  end;
  writeln(ans);
end.