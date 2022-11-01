var n,d,m,i: longint;
    x,y: array [1..100] of longint;
begin
readln (n,d);
readln (m);
for i:=1 to m do read (x[i], y[i]);
for i:=1 to m do if (abs(x[i]-y[i])<=d) and (x[i]+y[i]>=d) and (x[i]+y[i]<=(2*n-d)) then writeln ('YES') else writeln ('NO');
end.