var
  n,i:longint;
  a1,a2,b1,b2,x,y:int64;
begin
  readln(n);readln(a1,b1);a2:=a1;b2:=b1;
  for i:=2 to n do begin
    readln(x,y);
    if x<a2 then a2:=x;
    if x>a1 then a1:=x;
    if y<b2 then b2:=y;
    if y>b1 then b1:=y;
  end;
  if a1-a2>b1-b2 then writeln((a1-a2)*(a1-a2))
  else writeln((b1-b2)*(b1-b2));
end.