var a: array [1..500, 1..500] of char;
        i, j, n, c: integer;
begin
readln(n);
for i:=1 to n do
        begin
        for j:=1 to n do read(a[i, j]); readln;
        end;
for i:=1 to n-2 do
        for j:=1 to n-2 do
                if a[i, j]='X' then
                        if (a[i, j]=a[i+1, j+1]) and (a[i, j]=a[i+2, j]) and (a[i, j]=a[i, j+2]) and (a[i, j]=a[i+2, j+2]) then c:=c+1;
writeln(c);
end.