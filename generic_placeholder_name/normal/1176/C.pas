var n, i: integer;
        a: array [1..500000] of integer;
        n4, n8, n15, n16, n23, sum: longint;
begin
readln(n); for i:=1 to n do read(a[i]);
for i:=1 to n do
        if a[i]=4 then n4:=n4+1
        else if a[i]=8 then
                if n4=0 then sum:=sum+1
                else begin
                n4:=n4-1;
                n8:=n8+1;
                end
        else if a[i]=15 then
                if n8=0 then sum:=sum+1
                else begin
                n8:=n8-1;
                n15:=n15+1;
                end
        else if a[i]=16 then
                if n15=0 then sum:=sum+1
                else begin
                n15:=n15-1;
                n16:=n16+1;
                end
        else if a[i]=23 then
                if n16=0 then sum:=sum+1
                else begin
                n16:=n16-1;
                n23:=n23+1;
                end
        else if n23=0 then sum:=sum+1
        else n23:=n23-1;
sum:=sum+n23*5+n16*4+n15*3+n8*2+n4*1;
writeln(sum);
end.