var n, p, pow, req: int64;
    a, b, idx: array[1..100000] of int64;
    i: longint;

procedure qsort(const l, r: longint);
var i, j: longint;
    x, tmp: int64;
begin
    i := l;
    j := r;
    x := idx[random(r - l + 1) + l];
    while i <= j do begin
        while b[idx[i]] / a[idx[i]] < b[x] / a[x] do
            inc(i);
        while b[idx[j]] / a[idx[j]] > b[x] / a[x] do
            dec(j);
        if i <= j then begin
            tmp := idx[i];
            idx[i] := idx[j];
            idx[j] := tmp;
            inc(i);
            dec(j);
        end;
    end;
    if l < j then
        qsort(l, j);
    if i < r then
        qsort(i, r);
end;

begin
    randomize;
    readln(n, p);
    for i := 1 to n do begin
        read(a[i], b[i]);
        idx[i] := i;
    end;
    qsort(1, n);
    pow := 0;
    req := 0;
    for i := 1 to n do begin
        if pow < (req - p) * b[idx[i]] / a[idx[i]] then begin
            write((pow / (req - p)) : 0 : 8);
            exit;
        end;
        inc(pow, b[idx[i]]);
        inc(req, a[idx[i]]);
    end;
    if p >= req then
        write(-1)
    else
        write((pow / (req - p)) : 0 : 8);
end.