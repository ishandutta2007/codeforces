type arr=array[1..100000]of int64;
var
  a,b:arr;
  n,m,l,r,mid:int64;
  i:longint;
function ck:int64;
var
  i:longint;
  j,x:int64;
begin
  j:=1;
  for i:=1 to n do begin
    if a[i]-b[j]>mid then exit(0);
    x:=a[i]-b[j];
    if x<0 then x:=0 else inc(j);
    if j>m then exit(1);
    while a[i]-b[j]>=0 do begin
      inc(j);if j>m then exit(1);
    end;
    while (b[j]-a[i]+x*2<=mid)or
    ((b[j]-a[i])*2+x<=mid) do begin
      inc(j);if j>m then exit(1);
    end;
  end;
  exit(0);
end;
begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(b[i]);
  l:=0;r:=trunc(10e11);
  mid:=(l+r) shr 1;
  while l<r do begin
    if ck=0 then l:=mid+1 else r:=mid;
    mid:=(l+r) shr 1;
  end;
  writeln(mid);
end.