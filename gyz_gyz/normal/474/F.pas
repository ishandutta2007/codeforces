type xx=array[1..3]of longint;
const mx=131071;
var
  a:array[1..mx*2+1]of xx;
  l,r:array[1..mx*2+1]of longint;
  n,m,i,x,y:longint;
  ans:xx;
function gcd(x,y:longint):longint;
begin
  if y=0 then exit(x) else exit(gcd(y,x mod y));
end;
function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;
function f(x,y,p:longint):xx;
var q,w,e:xx;
begin
  if (x=l[p])and(y=r[p]) then exit(a[p]);
  if y<=r[p*2] then exit(f(x,y,p*2));
  if x>=l[p*2+1] then exit(f(x,y,p*2+1));
  q:=f(x,r[p*2],p*2);w:=f(l[p*2+1],y,p*2+1);
  e[1]:=gcd(q[1],w[1]);e[2]:=min(q[2],w[2]);e[3]:=0;
  if e[2]=q[2] then inc(e[3],q[3]);
  if e[2]=w[2] then inc(e[3],w[3]);
  exit(e);
end;
begin
  readln(n);
  for i:=1 to mx+1 do a[i+mx,2]:=maxlongint;
  for i:=1 to n do begin
    read(a[mx+i,1]);
    a[mx+i,2]:=a[mx+i,1];
    a[mx+i,3]:=1;
  end;
  for i:=mx downto 1 do begin
    a[i,1]:=gcd(a[i*2,1],a[i*2+1,1]);
    a[i,2]:=min(a[i*2,2],a[i*2+1,2]);
    if a[i*2,2]=a[i,2] then inc(a[i,3],a[i*2,3]);
    if a[i*2+1,2]=a[i,2] then inc(a[i,3],a[i*2+1,3]);
  end;
  l[1]:=1;r[1]:=mx+1;
  for i:=1 to mx do begin
    l[i*2]:=l[i];r[i*2]:=(l[i]+r[i]) shr 1;
    l[i*2+1]:=r[i*2]+1;r[i*2+1]:=r[i];
  end;
  readln(m);
  for i:=1 to m do begin
    readln(x,y);ans:=f(x,y,1);
    if ans[1]<>ans[2] then writeln(y-x+1)
    else writeln(y-x+1-ans[3]);
  end;
end.