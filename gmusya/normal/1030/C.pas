var k1,n,i,j,k,s: longint;
    s1: string;
    a,b,c: array [1..100] of longint;
begin
readln (n);
readln (s1);
for i:=1 to n do 
    begin
    if s1[i]='0' then a[i]:=0;
    if s1[i]='1' then a[i]:=1;
    if s1[i]='2' then a[i]:=2;
    if s1[i]='3' then a[i]:=3;
    if s1[i]='4' then a[i]:=4;
    if s1[i]='5' then a[i]:=5;
    if s1[i]='6' then a[i]:=6;
    if s1[i]='7' then a[i]:=7;
    if s1[i]='8' then a[i]:=8;
    if s1[i]='9' then a[i]:=9;
    end;
i:=1;
while (i<=n) do
    begin
    s:=s+a[i];
    b[i]:=s;
    i:=i+1;
    end;
i:=2;
j:=1;
while (i<100) do
    begin
    if (s mod i = 0) then 
        begin
        c[j]:=i;
        j:=j+1;
        end;
    i:=i+1;
    end;
k:=j-1;
k1:=0;
for j:=1 to k do
    begin
    s:=0;
    for i:=1 to n do
        begin
        s:=s+a[i];
        if s>b[n] div c[j] then break;
        if s=b[n] div c[j] then s:=0;
        end;
    if (s=0) and (i=n) then k1:=1;
    end;
if k1=1 then writeln ('YES') else writeln ('NO');
end.