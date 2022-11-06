const mx:longint=1000000007;
var
  st,ed,nt,t,w,fa,a:array[1..5000]of int64;
  d,n,m,i,x,y:longint;
  ans:int64;
procedure build(x:longint);
var
  r,dl:array[1..5000]of int64;
  i,s,e:longint;
begin
  for i:=1 to n do r[i]:=0;
  for i:=1 to n do a[i]:=0;
  r[x]:=1;s:=1;e:=1;dl[1]:=x;fa[x]:=0;
  while s<=e do begin
    i:=st[dl[s]];
    while i<>0 do begin
      if r[t[i]]=0 then begin
        inc(e);dl[e]:=t[i];
        r[t[i]]:=1;fa[t[i]]:=dl[s];
      end;
      i:=nt[i];
    end;
    inc(s);
  end;
end;
procedure f(x,y:longint);
var i:longint;
begin
  i:=st[x];a[x]:=1;
  while i<>0 do begin
    if fa[x]<>t[i] then begin
      f(t[i],y);
      if ((w[t[i]]<w[y])or(w[t[i]]=w[y])and(t[i]<y))and
      (w[y]-w[t[i]]<=d) then a[x]:=(a[x]+a[x]*a[t[i]]) mod mx;
    end;
    i:=nt[i];
  end;
end;
begin
  readln(d,n);
  for i:=1 to n do read(w[i]);
  for i:=1 to n-1 do begin
    readln(x,y);inc(m);
    if st[x]=0 then st[x]:=m else nt[ed[x]]:=m;
    ed[x]:=m;t[m]:=y;inc(m);
    if st[y]=0 then st[y]:=m else nt[ed[y]]:=m;
    ed[y]:=m;t[m]:=x;
  end;
  for i:=1 to n do begin
    build(i);f(i,i);ans:=(ans+a[i]) mod mx;
  end;
  writeln(ans);
end.