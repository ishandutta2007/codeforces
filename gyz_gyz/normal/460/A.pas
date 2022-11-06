var n,m,ans,p:longint;
begin
  readln(n,m);p:=n;ans:=n;
  while p>=m do begin
    inc(ans,p div m);
    p:=p div m+p mod m;
  end;
  writeln(ans);
end.