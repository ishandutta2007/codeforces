const mx=1048576;
var
  a,p,v,t,w,b,c:array[1..2000000]of longint;
  n,i:longint;
  ans:int64;
procedure sort1(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;x:=p[(l+r) shr 1];
  repeat
    while p[i]<x do inc(i);
    while x<p[j] do dec(j);
    if i<=j then begin
      y:=p[i];p[i]:=p[j];p[j]:=y;
      y:=v[i];v[i]:=v[j];v[j]:=y;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then sort1(l,j);
  if i<r then sort1(i,r);
end;
procedure sort2(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;x:=v[(l+r) shr 1];
  repeat
    while v[i]<x do inc(i);
    while x<v[j] do dec(j);
    if i<=j then begin
      y:=t[i];t[i]:=t[j];t[j]:=y;
      y:=v[i];v[i]:=v[j];v[j]:=y;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then sort2(l,j);
  if i<r then sort2(i,r);
end;
procedure ic(x:longint);inline;
begin
  while x<=mx do begin
    inc(a[x]);inc(x,x and (-x));
  end;
end;
function pp(x:longint):int64;inline;
var yy:int64;
begin
  yy:=0;
  while x>0 do begin
    inc(yy,a[x]);dec(x,x and (-x));
  end;
  exit(yy);
end;
begin
  readln(n);
  for i:=1 to n do read(p[i]);
  for i:=1 to n do v[i]:=i;
  sort1(1,n);t[1]:=1;
  for i:=2 to n do
    if p[i]=p[i-1] then t[i]:=t[i-1] else t[i]:=t[i-1]+1;
  sort2(1,n);
  for i:=1 to n do begin
    inc(w[t[i]]);b[i]:=w[t[i]];
  end;
  fillchar(w,sizeof(w),0);
  for i:=n downto 1 do begin
    inc(w[t[i]]);c[i]:=w[t[i]];
  end;
  for i:=n downto 1 do begin
    if b[i]>1 then inc(ans,pp(b[i]-1));
    ic(c[i]);
  end;
  writeln(ans);
end.