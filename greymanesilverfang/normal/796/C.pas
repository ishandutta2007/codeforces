uses math;

var n, MS, CM, CM1, AM1, ans: longint;
    a, u, v, AM: array[1..300000] of longint;

procedure input;
var i: longint;
begin
    readln(n);
    for i := 1 to n do
        read(a[i]);
    readln;
    for i := 1 to n - 1 do
        readln(u[i], v[i]);
end;

function sol1: longint;
var i: longint;
begin
    CM1 := 0;
    for i := 1 to n do
        if a[i] = MS - 1 then
            inc(CM1);
    AM1 := 0;
    for i := 1 to n - 1 do
        if (a[u[i]] = MS) or (a[v[i]] = MS) then
            if (a[u[i]] = MS - 1) or (a[v[i]] = MS - 1) then
                inc(AM1);
    if CM1 = AM1 then
        exit(MS)
    else
        exit(MS + 1);
end;

function sol2: longint;
var i: longint;
begin
    fillchar(AM, sizeof(AM), 0);
    for i := 1 to n - 1 do begin
        inc(AM[u[i]], ord(a[v[i]] = MS));
        inc(AM[v[i]], ord(a[u[i]] = MS));
    end;
    for i := 1 to n do
        if AM[i] + ord(a[i] = MS) = CM then
            exit(MS + 1);
    exit(MS + 2);
end;

procedure run;
var i: longint;
begin
    MS := low(longint);
    for i := 1 to n do
        MS := max(MS, a[i]);
    CM := 0;
    for i := 1 to n do
        if a[i] = MS then
            inc(CM);
    if CM = 1 then
        ans := sol1
    else
        ans := sol2;
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