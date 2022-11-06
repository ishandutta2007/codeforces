var
  a,b:array[1..5000]of longint;
  n,i,j,x:longint;
procedure sort(l,r:longint);
var i,j,x,y,z:longint;
begin
  i:=l;j:=r;
  x:=a[(l+r) div 2];
  z:=b[(l+r) div 2];
  repeat
    while (a[i]<x)or(a[i]=x)and(b[i]<z) do inc(i);
    while (x<a[j])or(x=a[j])and(z<b[j]) do dec(j);
    if i<=j then begin
      y:=a[i];a[i]:=a[j];a[j]:=y;
      y:=b[i];b[i]:=b[j];b[j]:=y;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n);
  for i:=1 to n do readln(a[i],b[i]);
  sort(1,n);
  for i:=1 to n-1 do
    if b[i]>b[i+1] then b[i+1]:=a[i+1];
  writeln(b[n]);
end.