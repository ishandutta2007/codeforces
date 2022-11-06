const mx=131071;
var
  a,w,wr,dp1,dp2,s,l,r:array[1..mx*2+1]of longint;
  n,i,ans:longint;
procedure ins(x,z,p:longint);
begin
  if z>a[p] then a[p]:=z;
  if (x=l[p])and(x=r[p]) then exit;
  if x<=r[p*2] then begin
    ins(x,z,p*2);exit;
  end else begin
    ins(x,z,p*2+1);exit;
  end;
end;
function fd(x,y,p:longint):longint;
var c,q:longint;
begin
  if (x=l[p])and(y=r[p]) then exit(a[p]);
  if y<=r[p*2] then exit(fd(x,y,p*2));
  if x>=l[p*2+1] then exit(fd(x,y,p*2+1));
  c:=fd(x,r[p*2],p*2);q:=fd(l[p*2+1],y,p*2+1);
  if c>q then exit(c) else exit(q);
end;
begin
  readln(n);l[1]:=1;r[1]:=mx+1;
  for i:=1 to mx do begin
    l[i*2]:=l[i];r[i*2]:=(l[i]+r[i]) div 2;
    l[i*2+1]:=(l[i]+r[i]) div 2+1;r[i*2+1]:=r[i];
  end;
  for i:=1 to n do read(w[i]);
  for i:=1 to n do begin
    if w[i]>1 then
      dp1[i]:=fd(1,w[i]-1,1)+1
    else dp1[i]:=1;
    ins(w[i],dp1[i],1);
  end;
  for i:=1 to mx*2+1 do a[i]:=0;
  for i:=n downto 1 do begin
    dp2[i]:=fd(w[i]+1,mx+1,1)+1;
    ins(w[i],dp2[i],1);
  end;
  for i:=1 to n do
    if dp1[i]>ans then ans:=dp1[i];
  for i:=1 to n do
    if dp1[i]+dp2[i]<=ans then wr[i]:=1;
  for i:=1 to n do
    if wr[i]=0 then inc(s[dp1[i]]);
  for i:=1 to n do
    if wr[i]=0 then
      if s[dp1[i]]=1 then wr[i]:=3 else wr[i]:=2;
  for i:=1 to n do write(wr[i]);
  writeln;
end.