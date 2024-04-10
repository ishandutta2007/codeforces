var n, tmp, cnt, i: longint;
    a: array[1..100000] of longint;

function gcd(const a, b: longint): longint;
begin
    if b = 0 then exit(a) else exit(gcd(b, a mod b));
end;

begin
    writeln('YES');
    readln(n);
    for i := 1 to n do read(a[i]);
    tmp := 0;
    for i := 1 to n do tmp := gcd(tmp, a[i]);
    if tmp > 1 then begin
        write(0);
        exit;
    end;
    cnt := 0;
    for i := 1 to n do
        if odd(a[i]) then
            if (i < n) and odd(a[i + 1]) then begin
                inc(cnt);
                a[i + 1] := 0;
            end else inc(cnt, 2);
    write(cnt);
end.