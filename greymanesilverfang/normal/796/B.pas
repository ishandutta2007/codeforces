var n, m, k, ans: longint;
    h, u, v: array[0..1000000] of longint;
    HOLE: array[0..1000000] of boolean;

procedure input;
var i: longint;
begin
    readln(n, m, k);
    for i := 1 to m do
        read(h[i]);
    readln;
    for i := 1 to k do
        readln(u[i], v[i]);
end;

function findbone: longint;
var cur, i: longint;
begin
    cur := 0;
    u[0] := 0;
    v[0] := 1;
    for i := 0 to k do begin
        if u[i] = cur then
            cur := v[i]
        else if v[i] = cur then
            cur := u[i];
        if HOLE[cur] then
            exit(cur);
    end;
    exit(cur);
end;

procedure run;
var i: longint;
begin
    fillchar(HOLE, sizeof(HOLE), 0);
    for i := 1 to m do
        HOLE[h[i]] := true;
    ans := findbone;
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