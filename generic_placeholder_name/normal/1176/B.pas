var t, i, n, j, r1, r2, r0, sum: integer;
        a: array [1..100] of longint;
begin
readln(t);
for i:=1 to t do
        begin
        readln(n); r0:=0; r1:=0; r2:=0;
        for j:=1 to n do read(a[j]); readln;
        for j:=1 to n do
                if a[j] mod 3 = 0 then r0:=r0+1
                else if a[j] mod 3 = 1 then r1:=r1+1
                else r2:=r2+1;
        if r2>r1 then sum:=r0+r1+(r2-r1) div 3
        else sum:=r0+r2+(r1-r2) div 3;
        writeln(sum);
        end;
end.