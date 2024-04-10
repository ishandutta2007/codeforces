var
i, n: longint;
curr, ans: int64;
a: array[0..1000000] of longint;

begin
read(n);
a[0] := Maxint;
for i := 1 to n do read(a[i]);
curr := 0;
ans := 0;
for i := 1 to n do begin
if a[i]=a[i-1] then begin
inc(curr);
ans := ans + curr;
end else curr := 0;
inc(ans);
end;
write(ans);
end.