var n, q, i: longint;
    a, p, k: array[1..100000] of longint;
    f: array[1..100000, 1..500] of longint;

function val(const p, k: longint): longint;
var ans: longint = 1;
begin
    if (k <= 500) and (f[p, k] > 0) then
        exit(f[p, k]);
    if p + a[p] + k <= n then
        inc(ans, val(p + a[p] + k, k));
    if k <= 500 then
        f[p, k] := ans;
    exit(ans);
end;

begin
    readln(n);
    for i := 1 to n do
        read(a[i]);
    readln;
    fillchar(f, sizeof(f), 0);
    readln(q);
    for i := 1 to q do begin
        readln(p[i], k[i]);
        writeln(val(p[i], k[i]));
    end;
end.