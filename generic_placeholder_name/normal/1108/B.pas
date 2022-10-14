var n, i, j, tmp: integer;
        a: array [0..128] of integer;
        c: array [1..128] of boolean;
begin
readln(n);
for i:=1 to n do read(a[i]);
for i:=1 to n-1 do
        for j:=i+1 to n do
                if a[i]>a[j] then
                        begin
                        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
                        end;
write(a[n], ' ');
for i:=1 to n do
        if (a[n] mod a[i] = 0) and (a[i]<>a[i-1]) then c[i]:=true;
i:=n; while c[i] do i:=i-1;
writeln(a[i]);
end.