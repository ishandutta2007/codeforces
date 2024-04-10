var
i, j, n, m: longint;
flag: boolean;

begin
read(n, m);

for i := n+1 to m-1 do begin
flag := true;
for j := 2 to i-1 do
if i mod j = 0 then
flag := false;
if flag then begin
write('NO');
halt;
end;
end;

for i := 2 to m-1 do
if m mod i = 0 then begin
write('NO');
halt;
end;

write('YES');
i := i;
end.