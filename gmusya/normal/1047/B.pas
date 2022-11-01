var max,i,n: longint;
    a,x,y: array [1..100000] of longint;
begin
readln (n);
for i:=1 to n do
    begin
    readln (x[i],y[i]);
    a[i]:=x[i]+y[i];
    end;
max:=0;    
for i:=1 to n do if a[i]>max then max:=a[i];
writeln (max);
end.