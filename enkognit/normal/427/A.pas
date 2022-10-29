var
  a,b,c : array[1..1000000] of longint;
  k,l,n,m,s,f,k1,k2,k3,t : longint;
  i,j,z,x : longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
   if a[i]>0 then l:=l+a[i] else
   if a[i]<0 then
   if l>0 then l:=l-1 else
   k:=k+1;
  writeln(k);
end.