var
 a,b,c,d,s,f : array[1..100000] of longint;
 n,i,j,m,l,u,t,k : longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  readln(a[i],b[i]);
  inc(s[a[i]]);
  inc(f[b[i]]);
  c[i]:=a[i];
  d[i]:=b[i];
 end;
 for i:=1 to n do
 begin
  k:=s[b[i]];
  c[i]:=n-1+k;
  d[i]:=n-1-k;
 end;
 for i:=1 to n do writeln(c[i],' ',d[i]);
end.