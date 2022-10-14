var a: array [1..200] of integer;
        n, k, b, i, j, sum, tmp, max: integer;
begin
for i:=1 to 200 do a[i]:=0;
readln(n, k);
for i:=1 to n do read(a[i]);
sum:=0; max:=0; for i:=1 to n do sum:=sum+a[i];
for i:=1 to k do
        begin
        tmp:=sum;
        for j:=0 to n div k do tmp:=tmp-a[j*k+i];
        if abs(tmp)>max then max:=abs(tmp);
        end;
writeln(max);
end.