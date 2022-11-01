var a,c,x:array[1..300000] of int64;
    j,h,sum,l,i,n,m,k:int64;
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
  readln (n,h);
  for i:=1 to n do read (a[i]);
  for i:=1 to n do
  begin
    sum:=0;
    for j:=1 to i do x[j]:=a[j];
    sort (1,i);
    j:=i;
    while (j>=1) do
    begin
      sum:=sum+x[j];
      j:=j-2;
    end;
    if sum>h then break;
  end;
  if sum>h then writeln (i-1) else writeln (i);
end.