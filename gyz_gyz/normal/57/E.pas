const mx:int64=1000000007;
const
  u1:array[1..8]of longint=(-2,-1,1,2,2,1,-1,-2);
  u2:array[1..8]of longint=(1,2,2,1,-1,-2,-2,-1);
var
  p,q:array[0..4000000]of longint;
  a:array[-1000..1000,-1000..1000]of longint;
  i,j,x,y,h,t,ans:longint;
  n,m,r,x1,x2,x3:int64;
begin
  readln(n,m);
  fillchar(a,sizeof(a),$7f);
  for i:=1 to m do begin
    readln(x,y);a[x,y]:=-1;
  end;
  a[0,0]:=0;p[1]:=0;q[1]:=0;h:=1;t:=1;r:=n;
  if n>500 then n:=500;
  while h<=t do begin
    if (x1=0)and(a[p[h],q[h]]=n-2) then x1:=ans+1;
    if (x2=0)and(a[p[h],q[h]]=n-1) then x2:=ans+1;
    if (x3=0)and(a[p[h],q[h]]=n) then x3:=ans+1;
    if a[p[h],q[h]]=n then break;
    for i:=1 to 8 do
      if a[p[h],q[h]]+1<a[p[h]+u1[i],q[h]+u2[i]] then begin
        inc(t);p[t]:=p[h]+u1[i];q[t]:=q[h]+u2[i];
        a[p[t],q[t]]:=a[p[h],q[h]]+1;inc(ans);
      end;
    inc(h);
  end;
  if (r=n)or(h>t) then begin
    writeln(ans+1);halt;
  end;
  r:=(r-n+3) mod mx;
  x3:=(x1+x3-x2-x2) mod mx;
  x2:=(x2-x1) mod mx;
  writeln((x1+(r-1)*x2+(r-1)*(r-2) div 2 mod mx*x3) mod mx);
end.