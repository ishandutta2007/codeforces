var
  n,k,i:longint;
  a:array[1..100]of longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;x:=a[(l+r) shr 1];
  repeat
    while a[i]>x do inc(i);
    while x>a[j] do dec(j);
    if i<=j then begin
      y:=a[i];a[i]:=a[j];a[j]:=y;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  sort(1,n);i:=k;
  while (i<n)and(a[i]=a[i+1]) do inc(i);
  while (i>0)and(a[i]<1) do dec(i);
  writeln(i);
end.