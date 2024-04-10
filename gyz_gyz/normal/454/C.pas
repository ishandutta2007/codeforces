var
  n,m,i:longint;
  x,y,ans:extended;
function pw(x:extended;y:longint):extended;
var z:extended;
begin
  if y=1 then exit(x);
  z:=pw(x,y shr 1);z:=z*z;
  if y and 1=1 then z:=z*x;
  exit(z);
end;
begin
  readln(n,m);
  for i:=1 to n do begin
    y:=pw(i/n,m);
    ans:=ans+(y-x)*i;
    x:=y;
  end;
  writeln(ans:0:17);
end.