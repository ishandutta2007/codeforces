type xx=record
  a,b:longint;
end;
const mx=131071;
var
  a:array[1..mx*2+1]of xx;
  e,t:array[1..mx*2+1]of longint;
  dp:array[1..mx+1]of xx;
  l,r,nb,wr:array[1..mx+1]of longint;
  w,tp:array[1..mx+1]of int64;
  n,i,j,x:longint;
  r1,r2,ans:xx;
  d:int64;
procedure sort(l,r:longint);
var
  i,j:longint;
  x,y:int64;
begin
  i:=l;j:=r;x:=tp[(l+r) shr 1];
  repeat
    while tp[i]<x do inc(i);
    while x<tp[j] do dec(j);
    if i<=j then begin
      y:=tp[i];tp[i]:=tp[j];tp[j]:=y;
      y:=nb[i];nb[i]:=nb[j];nb[j]:=y;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
procedure ins(x:longint;y:xx;p:longint);
begin
  if y.a>a[p].a then a[p]:=y;
  if (x=e[p])and(x=t[p]) then exit;
  if x<=t[p*2] then ins(x,y,p*2) else ins(x,y,p*2+1);
end;
function fd(x,y,p:longint):xx;
var c,v:xx;
begin
  if (x=e[p])and(y=t[p]) then exit(a[p]);
  if y<=t[p*2] then exit(fd(x,y,p*2));
  if x>=e[p*2+1] then exit(fd(x,y,p*2+1));
  c:=fd(x,t[p*2],p*2);v:=fd(e[p*2+1],y,p*2+1);
  if c.a>v.a then exit(c) else exit(v);
end;
begin
  readln(n,d);
  for i:=1 to n do begin
    read(w[i]);tp[i]:=w[i];nb[i]:=i;
  end;
  sort(1,n);x:=1;
  for i:=1 to n do begin
    while (w[nb[x]]+d<=w[nb[i]])and(x<n) do inc(x);
    l[nb[i]]:=x;
  end;
  x:=n;e[1]:=1;t[1]:=mx+1;
  for i:=n downto 1 do begin
    while (w[nb[x]]-d>=w[nb[i]])and(x>1) do dec(x);
    r[nb[i]]:=x;
  end;
  for i:=1 to n do w[nb[i]]:=i;
  for i:=1 to mx do begin
    e[i*2]:=e[i];t[i*2]:=(e[i]+t[i]) shr 1;
    e[i*2+1]:=t[i*2]+1;t[i*2+1]:=t[i];
  end;
  for i:=1 to n do begin
    r1.a:=0;r1.b:=0;r2.a:=0;r2.b:=0;
    if l[i]>1 then r1:=fd(1,l[i]-1,1);
    if r[i]<n then r2:=fd(r[i]+1,n,1);
    if r1.a>r2.a then dp[i]:=r1 else dp[i]:=r2;
    inc(dp[i].a);r1:=dp[i];r1.b:=i;ins(w[i],r1,1);
  end;
  for i:=1 to n do
    if dp[i].a>ans.a then begin
      ans:=dp[i];x:=i;
    end;
  writeln(ans.a);wr[1]:=x;x:=1;
  while ans.b<>0 do begin
    inc(x);wr[x]:=ans.b;ans:=dp[ans.b];
  end;
  while x>0 do begin
    write(wr[x],' ');dec(x);
  end;
  writeln;
end.