var h, w, i, j, x, y: integer;
        ans: boolean;
        a: array [1..501, 1..500] of char;
begin
readln(h, w);
for i:=1 to h do
        begin
        for j:=1 to w do read(a[i, j]); readln;
        end;
ans:=true;
for i:=2 to h-1 do
        for j:=2 to w-1 do
                if (a[i, j] = '*') and  (a[i-1, j] = '*') and  (a[i+1, j] = '*') and  (a[i, j-1] = '*') and  (a[i, j+1] = '*') then
                        begin
                        x:=i; y:=j;
                        break;
                        end;
if (x=0) and (y=0) then begin writeln('NO'); halt; end;
for i:=1 to h do
        for j:=1 to w do
                begin
                if (i<>x) and (j<>y) then
                        if (a[i, j]='*') then ans:=false;
                if i=x then
                        begin
                        if j<y then
                                if (a[i, j] = '*') and (a[i, j+1] = '.') then ans:=false;
                        if j>y then
                                if (a[i, j] = '*') and (a[i, j-1] = '.') then ans:=false;
                        end;
                if j=y then
                        begin
                        if i<x then
                                if (a[i, j] = '*') and (a[i+1, j] = '.') then ans:=false;
                        if i>x then
                                if (a[i, j] = '*') and (a[i-1, j] = '.') then ans:=false;
                        end;
                end;
if ans then writeln('YES') else writeln('NO');
end.