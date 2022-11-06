const eps:extended=10e-8;
var
  a:array[1..20000]of extended;
  n,i:longint;
  k,l,r,mid,a1,a2:extended;
begin
  readln(n,k);k:=1-k/100;
  for i:=1 to n do read(a[i]);
  l:=0;r:=2000;mid:=(l+r)/2;
  while r-l>eps do begin
    a1:=0;a2:=0;
    for i:=1 to n do
      if a[i]>mid then a1:=a1+a[i]-mid
      else a2:=a2+mid-a[i];
    if a1*k<a2 then r:=mid else l:=mid;
    mid:=(l+r)/2;
  end;
  writeln(mid:0:6);
end.