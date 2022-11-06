var
  a,f,h,t,y,nt,w,g,gg:array[1..1000000]of longint;
  n,m,k,i,xx,yy,p:longint;
function max(x,y:longint):longint;inline;
begin
  if x>y then exit(x) else exit(y);
end;
function gf(x:longint):longint;
begin
  if f[x]=x then exit(x);
  f[x]:=gf(f[x]);exit(f[x]);
end;
procedure bf(rt:longint;gt:boolean);
var a,b,i:longint;
begin
  a:=1;b:=1;g[1]:=rt;gg[1]:=0;w[rt]:=1;
  while a<=b do begin
    i:=h[g[a]];
    if i=0 then begin
      inc(a);continue;
    end;
    if w[y[i]]=0 then begin
      inc(b);gg[b]:=gg[a]+1;
      g[b]:=y[i];w[y[i]]:=1;
    end;
    while nt[i]<>0 do begin
      i:=nt[i];
      if w[y[i]]=0 then begin
        inc(b);gg[b]:=gg[a]+1;
        g[b]:=y[i];w[y[i]]:=1;
      end;
    end;
    inc(a);
  end;
  xx:=g[b];yy:=gg[b];
  if gt then
    for i:=1 to b do w[g[i]]:=0;
end;
begin
  readln(n,m,k);
  for i:=1 to n do f[i]:=i;
  for i:=1 to m do begin
    readln(xx,yy);
    inc(p);y[p]:=yy;
    if h[xx]=0 then h[xx]:=p else nt[t[xx]]:=p;
    t[xx]:=p;
    inc(p);y[p]:=xx;
    if h[yy]=0 then h[yy]:=p else nt[t[yy]]:=p;
    t[yy]:=p;
    if gf(xx)<>gf(yy) then f[f[xx]]:=f[yy];
  end;
  for i:=1 to n do
    if w[i]=0 then begin
      bf(i,true);bf(xx,false);a[gf(i)]:=yy;
    end;
  for i:=1 to k do begin
    read(xx);
    if xx=2 then begin
      readln(xx,yy);
      if gf(xx)<>gf(yy) then begin
        a[f[yy]]:=max(max(a[f[xx]],a[f[yy]]),((a[f[xx]]+1) shr 1)+((a[f[yy]]+1) shr 1)+1);
        f[f[xx]]:=f[yy];
      end;
    end else begin
      readln(xx);writeln(a[gf(xx)]);
    end;
  end;
end.