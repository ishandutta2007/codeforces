var
  a,b,c:array[0..200000]of int64;
  n,m,w,l,r,mid:int64;
  i:longint;
function ck(x:int64):boolean;
var p:int64;
begin
  c[0]:=0;p:=0;
  for i:=1 to w do begin
    c[i]:=c[i-1];
    if c[i]+a[i]<x then begin
      b[i]:=x-a[i]-c[i];inc(c[i],b[i]);inc(p,b[i]);
      if p>m then exit(false);
    end else b[i]:=0;
  end;
  for i:=w+1 to n do begin
    c[i]:=c[i-1]-b[i-w];
    if c[i]+a[i]<x then begin
      b[i]:=x-a[i]-c[i];inc(c[i],b[i]);inc(p,b[i]);
      if p>m then exit(false);
    end else b[i]:=0;
  end;
  exit(true);
end;
begin
  readln(n,m,w);
  for i:=1 to n do read(a[i]);
  l:=0;r:=10000000000;
  mid:=(l+r+1) div 2;
  while l<r do begin
    if ck(mid) then l:=mid else r:=mid-1;
    mid:=(l+r+1) div 2;
  end;
  writeln(mid);
end.