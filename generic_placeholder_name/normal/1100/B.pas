var n, m, i, j, c, tmp: longint;
        a, b: array [1..100000] of longint;
        s: array [1..100000] of boolean;
begin
readln(n, m);
for i:=1 to m do read(a[i]);readln;
for i:=1 to m do b[i]:=0; c:=0; tmp:=0;
for i:=1 to m do
        begin
        if b[a[i]]<=c then tmp:=tmp+1;
        b[a[i]]:=b[a[i]]+1;
        if tmp=n then
                begin
                s[i]:=true;
                c:=c+1;
                for j:=1 to n do
                        if b[j]<=c then tmp:=tmp-1;
                end
        else s[i]:=false;
        end;
for i:=1 to m do
        if s[i] then write(1)
        else write(0);
end.