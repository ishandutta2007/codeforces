var
  n,a,b,u,ans:int64;
  i:longint;
begin
  readln(n,a,b);n:=n*6;
  if n<=a*b then begin
    writeln(a*b);writeln(a,' ',b);halt;
  end;
  if a>b then begin
    u:=a;a:=b;b:=u;u:=1;
  end;
  ans:=a;
  for i:=a+1 to trunc(sqrt(n)) do begin
    if (n-1) div i+1<b then break;
    if i*((n-1) div i+1)<ans*((n-1) div ans+1) then ans:=i;
  end;
  a:=ans;b:=(n-1) div ans+1;
  writeln(a*b);
  if u=0 then writeln(a,' ',b) else writeln(b,' ',a);
end.