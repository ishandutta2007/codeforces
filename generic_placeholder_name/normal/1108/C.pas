var s: ansistring;
        i, j, k, max: longint;
        r, g, b: array [0..2] of longint;
        ans: array [0..2] of char;
begin
readln(i);
readln(s);
for i:=1 to length(s) do
        if s[i]='R' then r[i mod 3]:=r[i mod 3]+1
        else if s[i]='G' then g[i mod 3]:=g[i mod 3]+1
        else b[i mod 3]:=b[i mod 3]+1;
for i:=0 to 2 do
        for j:=0 to 2 do
                for k:=0 to 2 do
                        if (i<>j) and (j<>k) and (k<>i) then
                                if r[i]+g[j]+b[k]>max then
                                        begin
                                        max:=r[i]+g[j]+b[k];
                                        ans[i]:='R'; ans[j]:='G'; ans[k]:='B';
                                        end;
writeln(length(s)-max);
for i:=1 to length(s) do write(ans[i mod 3]);
end.