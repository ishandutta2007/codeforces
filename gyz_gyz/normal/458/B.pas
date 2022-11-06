var
  a,b:array[1..100000]of int64;
  an1,an2,p,t,w,n,m:int64;
  i:longint;
begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(b[i]);
  for i:=1 to n do inc(p,a[i]);
  an1:=p*m;
  for i:=1 to m do
    if b[i]>t then begin
      t:=b[i];w:=i;
    end;
  for i:=1 to m do
    if (i<>w)and(b[i]<p) then dec(an1,p-b[i]);
  p:=0;
  for i:=1 to m do inc(p,b[i]);
  an2:=p*n;t:=0;
  for i:=1 to n do
    if a[i]>t then begin
      t:=a[i];w:=i;
    end;
  for i:=1 to n do
    if (i<>w)and(a[i]<p) then dec(an2,p-a[i]);
  if an1>an2 then writeln(an2) else writeln(an1);
end.