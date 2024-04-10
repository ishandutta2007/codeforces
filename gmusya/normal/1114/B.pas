var c,a,x:array[1..300000] of int64;
    gran,sum,l,i,n,m,k:int64;
procedure sort(l,r:int64);
var
  i,j,x1,y1,m: int64;
begin
  i:=l;
  j:=r;
  m:=round ((l+r)/2);
  x1:=x[m];
  repeat
    while x[i]<x1 do inc(i);
    while x[j]>x1 do dec(j);
    if i<=j then 
     begin
      y1:=x[i];
      x[i]:=x[j];
      x[j]:=y1;
      y1:=c[i];
      c[i]:=c[j];
      c[j]:=y1;
      inc(i); 
      dec(j); 
     end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
 
begin
  readln (n,m,k);
  for i:=1 to n do read (a[i]);
  for i:=1 to n do c[i]:=i;
  for i:=1 to n do x[i]:=a[i];
  sort(1,n);
  gran:=x[n-m*k+1];
  for i:=n-m*k+1 to n do sum:=sum+x[i];
  writeln (sum);
  for i:=1 to m*k do x[i]:=c[n-i+1];
  sort (1,m*k);
  for i:=1 to m*k-1 do if i mod m = 0 then write (x[i], ' ');
end.