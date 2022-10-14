var s, a: string;
begin
readln(s);
readln(a);
if (s[1]=a[1]) or (s[1]=a[4]) or (s[1]=a[7]) or (s[1]=a[10]) or (s[1]=a[13]) then writeln('YES')
else if (s[2]=a[2]) or (s[2]=a[5]) or (s[2]=a[8]) or (s[2]=a[11]) or (s[2]=a[14]) then writeln('YES')
else writeln('NO');
end.