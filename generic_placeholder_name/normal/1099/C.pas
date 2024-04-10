var s: ansistring;
        k, m, n, i, l, j: integer;
begin
readln(s);
readln(k);
l:=length(s);
for i:=1 to length(s) do
        if s[i]='?' then l:=l-1
        else if s[i]='*' then l:=l-1;
i:=1;
while i<=length(s) do
        begin
        if s[i]='?' then
                if l>k then
                        begin
                        delete(s, i-1, 2);
                        l:=l-1;
                        end
                else delete(s, i, 1)
        else if s[i]='*' then
                if l>k then
                        begin
                        delete(s, i-1, 2);
                        l:=l-1;
                        end
                else if l<k then
                        begin
                        delete(s, i, 1);
                        for j:=1 to k-l do insert(s[i-1], s, i-1);
                        i:=i+j;
                        l:=k;
                        end
                else delete(s, i, 1)
        else i:=i+1;
        end;
if length(s)<>k then writeln('Impossible')
else writeln(s);
end.