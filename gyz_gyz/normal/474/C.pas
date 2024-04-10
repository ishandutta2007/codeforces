var
  a,b,x,y,p,q,aa,bb:array[1..4]of int64;
  n,i,ans:longint;
function dis(i,j:longint):int64;
begin
  exit((p[i]-p[j])*(p[i]-p[j])+(q[i]-q[j])*(q[i]-q[j]));
end;
procedure pp(g:longint);
var
  i,j,r,rr:longint;
  d,e:int64;
begin
  d:=maxlongint;e:=0;
  for i:=1 to 4 do
    for j:=1 to 4 do
      if i<>j then begin
        if dis(i,j)<d then d:=dis(i,j);
        if dis(i,j)>e then e:=dis(i,j);
      end;
  if (d*2<>e)or(d=0) then exit;
  for i:=1 to 4 do begin
    r:=0;rr:=0;
    for j:=1 to 4 do
      if i<>j then begin
        if dis(i,j)=d then inc(r);
        if dis(i,j)=e then inc(rr);
      end;
    if (r<>2)or(rr<>1) then exit;
  end;
  if g<ans then ans:=g;
end;
procedure f(i,g:longint);
begin
  if i>4 then begin
    pp(g);exit;
  end;
  p[i]:=x[i]+a[i];
  q[i]:=y[i]+b[i];
  f(i+1,g);
  p[i]:=x[i]-b[i];
  q[i]:=y[i]+a[i];
  f(i+1,g+1);
  p[i]:=x[i]-a[i];
  q[i]:=y[i]-b[i];
  f(i+1,g+2);
  p[i]:=x[i]+b[i];
  q[i]:=y[i]-a[i];
  f(i+1,g+3);
end;
begin
  readln(n);
  while n>0 do begin
    dec(n);
    for i:=1 to 4 do begin
      readln(aa[i],bb[i],x[i],y[i]);
      a[i]:=aa[i]-x[i];
      b[i]:=bb[i]-y[i];
    end;
    ans:=1000;f(1,0);
    if ans=1000 then writeln(-1) else writeln(ans);
  end;
end.