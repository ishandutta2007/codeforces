var
  n,m,x,ans:int64;
begin
  readln(n,m);x:=(n-1) div 2+1;
  ans:=((x-1) div m+1)*m;
  if ans>n then writeln(-1) else writeln(ans);
end.