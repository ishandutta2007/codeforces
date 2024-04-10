var n,k,k1,i: longint;
    a,b: array [1..100] of longint;
begin
readln (n,k);
for i:=1 to n do read (a[i]);
for i:=1 to k do read (b[i]);
if k>=2 then writeln ('Yes') else
    begin
    for i:=1 to n do if a[i]=0 then a[i]:=b[1];
    for i:=1 to n-1 do if a[i]>a[i+1] then k1:=1;
    if k1=1 then writeln ('Yes') else writeln ('No');
    end;
end.