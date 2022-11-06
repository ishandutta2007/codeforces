var
  n,m,ps,i,mi:longint;
  ans,a,b:extended;
begin
  readln(n,m);a:=1;b:=1;ps:=(n-1)*m;
  if n>m then mi:=m else mi:=n;
  for i:=1 to n-1 do b:=b*(ps-i+1)/i;
  for i:=1 to mi do begin
    a:=a*(m-i+1)/i;
    ans:=ans+a*b*i*i/n/n;
    b:=b*(n-i)/(ps+i+1-n);
  end;
  ans:=ans*n;
  for i:=1 to n do ans:=ans*i/(n*m-n+i);
  writeln(ans:0:17);
end.