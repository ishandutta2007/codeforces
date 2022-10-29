uses math;

var n, m, k, ans: longint;
    a: array[1..100] of longint;

procedure input;
var i: longint;
begin
    readln(n, m, k);
    for i := 1 to n do
        read(a[i]);
end;

procedure run;
var i: longint;
begin
    ans := high(longint);
    for i := 1 to n do
        if (a[i] > 0) and (a[i] <= k) then
            ans := min(ans, 10 * abs(m - i));
end;

procedure output;
begin
    write(ans);
end;

begin
    input;
    run;
    output;
end.