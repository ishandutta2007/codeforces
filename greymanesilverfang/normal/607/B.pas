uses math;

const MaxN = 500;

var n, ans: longint;
    a: array[1 .. MaxN] of longint;

procedure input;
var i: longint;
begin
    readln(n);
    for i := 1 to n do
        read(a[i]);
end;

procedure run;
var i, j, k: longint;
    f: array[1 .. MaxN, -1 .. MaxN - 1] of longint;
begin
    fillchar(f, sizeof(f), 0);
    for j := 1 to n - 1 do
        for i := 1 to n - j do begin
            f[i, j] := high(longint);
            for k := 1 to j do
                f[i, j] := min(f[i, j], f[i, k - 1] + f[i + k, j - k] + 1);
            for k := 1 to (j + 1) div 2 do
                if a[i + k - 1] = a[i + j - k + 1] then
                    f[i, j] := min(f[i, j], f[i + k, j - 2 * k])
                else
                    break;
        end;
    ans := f[1, n - 1] + 1;
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