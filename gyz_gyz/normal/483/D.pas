const mx=131071;
var
  f,l,r:array[1..mx*2+1]of longint;
  a,b,c:array[1..mx+1]of longint;
  n,m,i:longint;
procedure ior(p,x,y,z:longint);
var i:longint;
begin
  if (x=l[p])and(y=r[p]) then begin
    f[p]:=f[p] or z;exit;
  end;
  if y<=(l[p]+r[p]) shr 1 then begin
    ior(p shl 1,x,y,z);exit;
  end;
  if x>(l[p]+r[p]) shr 1 then begin
    ior((p shl 1)+1,x,y,z);exit;
  end;
  ior(p shl 1,x,(l[p]+r[p]) shr 1,z);
  ior(p shl 1+1,((l[p]+r[p]) shr 1)+1,y,z);
end;
function ind(p,x,y:longint):longint;
var i:longint;
begin
  if (x=l[p])and(y=r[p]) then exit(f[p]);
  if y<=(l[p]+r[p]) shr 1 then
    exit(ind(p shl 1,x,y));
  if x>(l[p]+r[p]) shr 1 then
    exit(ind((p shl 1)+1,x,y));
  exit(ind(p shl 1,x,(l[p]+r[p]) shr 1) and
  ind(p shl 1+1,((l[p]+r[p]) shr 1)+1,y));
end;
begin
  readln(n,m);
  for i:=1 to m do readln(a[i],b[i],c[i]);
  l[1]:=1;r[1]:=mx+1;
  for i:=1 to mx do begin
    l[i shl 1]:=l[i];
    r[i shl 1]:=(l[i]+r[i]) shr 1;
    l[i shl 1+1]:=((l[i]+r[i]) shr 1)+1;
    r[i shl 1+1]:=r[i];
  end;
  for i:=1 to m do ior(1,a[i],b[i],c[i]);
  for i:=1 to mx do begin
    f[i shl 1]:=f[i] or f[i shl 1];
    f[(i shl 1)+1]:=f[i] or f[(i shl 1)+1];
  end;
  for i:=mx downto 1 do
    f[i]:=f[i shl 1] and f[(i shl 1)+1];
  for i:=1 to m do
    if ind(1,a[i],b[i])<>c[i] then begin
      writeln('NO');halt;
    end;
  writeln('YES');
  for i:=1 to n do write(f[mx+i],' ');
  writeln;
end.