var
  a,b,c,u,v,p:array[1..500000]of longint;
  n,m,i,w,ans:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;x:=p[l+random(r-l-1)+1];
  repeat
    while p[i]<x do inc(i);
    while x<p[j] do dec(j);
    if i<=j then begin
      y:=u[i];u[i]:=u[j];u[j]:=y;
      y:=v[i];v[i]:=v[j];v[j]:=y;
      y:=p[i];p[i]:=p[j];p[j]:=y;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n,m);randomize;
  for i:=1 to m do readln(u[i],v[i],p[i]);
  sort(1,m);
  for i:=1 to m do begin
    if a[u[i]]+1>a[v[i]] then begin
      if b[v[i]]=a[v[i]] then begin
        inc(w);c[w]:=v[i];
      end;
      if a[u[i]]+1>b[v[i]] then
        b[v[i]]:=a[u[i]]+1;
    end;
    if p[i+1]<>p[i] then begin
      while w>0 do begin
        a[c[w]]:=b[c[w]];dec(w);
      end;
    end;
  end;
  for i:=1 to n do
    if a[i]>ans then ans:=a[i];
  writeln(ans);
end.