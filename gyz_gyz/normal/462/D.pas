const mx=1000000007;
var
  a:array[1..100000,0..1]of int64;
  nt,s,t:array[1..100000]of longint;
  n,i,j,x:longint;
procedure f(x:longint);
var i:longint;
begin
  i:=s[x];
  while i<>0 do begin
    f(i);
    a[x,1]:=(a[x,1]*(a[i,0]+a[i,1])+a[x,0]*a[i,1]) mod mx;
    a[x,0]:=a[x,0]*(a[i,0]+a[i,1]) mod mx;
    i:=nt[i];
  end;
end;
begin
  readln(n);
  for i:=2 to n do begin
    read(x);inc(x);
    if s[x]=0 then s[x]:=i else nt[t[x]]:=i;
    t[x]:=i;
  end;
  for i:=1 to n do begin
    read(x);a[i,x]:=1;
  end;
  f(1);writeln(a[1,1]);
end.