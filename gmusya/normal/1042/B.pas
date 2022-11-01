var k12,k34,k56,k78,k1234,k5678,k1,k2,k3,k4,k5,k6,k7,k8,k,n,a,b,c,ab,ac,bc,abc,i: longint;
    arr: array [1..1000] of longint;
    s: array [1..1000] of string;
begin
readln (n);
a:=1000001;
b:=1000001;
c:=1000001;
ab:=1000001;
bc:=1000001;
ac:=1000001;
abc:=1000001;
for i:=1 to n do 
    begin
    read (arr[i]);
    readln (s[i]);
    end;
for i:=1 to n do
    begin
    if (s[i]=' A') and (arr[i]<a) then a:=arr[i];
    if (s[i]=' B') and (arr[i]<b) then b:=arr[i];
    if (s[i]=' C') and (arr[i]<c) then c:=arr[i];
    if ((s[i]=' AB') or (s[i]=' BA')) and (arr[i]<ab) then ab:=arr[i];
    if ((s[i]=' AC') or (s[i]=' CA')) and (arr[i]<ac) then ac:=arr[i];
    if ((s[i]=' BC') or (s[i]=' CB')) and (arr[i]<bc) then bc:=arr[i];
    if ((s[i]=' ABC') or (s[i]=' ACB') or (s[i]=' BAC') or (s[i]=' BCA') or (s[i]=' CAB') or (s[i]=' CBA')) and (arr[i]<abc) then abc:=arr[i];
    end;
if ((a=1000001) and (ab=1000001) and (ac=1000001) and (abc=1000001)) or ((b=1000001) and (ab=1000001) and (bc=1000001) and (abc=1000001)) or ((c=1000001) and (ac=1000001) and (bc=1000001) and (abc=1000001)) then writeln ('-1')
else
    begin
    k1:=a+b+c;
    k2:=ab+c;
    k3:=ac+b;
    k4:=bc+a;
    k5:=ab+bc;
    k6:=ac+bc;
    k7:=ab+ac;
    k8:=abc;
    k12:=min(k1,k2);
    k34:=min(k3,k4);
    k56:=min(k5,k6);
    k78:=min(k7,k8);
    k1234:=min(k12,k34);
    k5678:=min(k56,k78);
    k:=min(k1234,k5678);
    writeln (k);
    end;
end.