var s: string;
    n, cnt, i: longint;

begin
    readln(s);
    n := length(s);
    cnt := 0;
    for i := 1 to n div 2 do
        if s[i] <> s[n - i + 1] then
            inc(cnt);
    if (cnt = 0) and odd(n) or (cnt = 1) then
        write('YES')
    else
        write('NO');
end.