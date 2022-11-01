var t,i: longint;
    a,b,l,r,k: array [1..10000] of longint;
begin
  readln (t);
  for i:=1 to t do readln (a[i],b[i],l[i],r[i]);
  for i:=1 to t do k[i]:=a[i] div b[i] - (r[i] div b[i] - (l[i]-1) div b[i]);
  for i:=1 to t do writeln (k[i]);
end.