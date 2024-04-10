var
  n,m,x,xx:int64;
begin
  readln(n,m);
  x:=n div m;
  xx:=n mod m;
  writeln((x-1)*x div 2*(m-xx)+x*(x+1) div 2*xx,' ',(n-m+1)*(n-m) div 2);
end.