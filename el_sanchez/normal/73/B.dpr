program solution;

{$APPTYPE CONSOLE}

uses
    SysUtils, Math;

const
    MaxN = 100000;

type
    int = longint;

var
    i, m, n, curr, pos, bal, mine: int;
    p: string;
    ch: char;
    a, w: Array[1..MaxN] of int;
    s: array[1..MaxN] of string;

procedure swap(var x1, x2: int);
var
    x3: int;
begin
    x3 := x1;
    x1 := x2;
    x2 := x3;
end;

procedure swapstr(var x1, x2: string);
var
    x3: string;
begin
    x3 := x1;
    x1 := x2;
    x2 := x3;
end;

procedure Quicksort(l, r: int);
var
    i, j: int;
    x: int;
begin
    if l >= r then exit;
    i := l;
    j := r;
    x := a[l + random(r - l + 1)];
    repeat
        while a[i] > x do
            inc(i);
        while a[j] < x do
            dec(j);
        if i <= j then begin
            swap(a[i], a[j]);
            swapstr(s[i], s[j]);
            inc(i);
            dec(j);
        end;
    until i > j;
    Quicksort(i, r);
    Quicksort(l, j);
end;

procedure Quicksort2(l, r: int);
var
    i, j: int;
    x: string;
begin
    if l >= r then exit;
    i := l;
    j := r;
    x := s[l + random(r - l + 1)];
    repeat
        while s[i] < x do
            inc(i);
        while s[j] > x do
            dec(j);
        if i <= j then begin
            swap(a[i], a[j]);
            swapstr(s[i], s[j]);
            inc(i);
            dec(j);
        end;
    until i > j;
    Quicksort2(i, r);
    Quicksort2(l, j);
end;

procedure Quicksort3(l, r: int);
var
    i, j: int;
    x: int;
begin
    if l >= r then exit;
    i := l;
    j := r;
    x := w[l + random(r - l + 1)];
    repeat
        while w[i] < x do
            inc(i);
        while w[j] > x do
            dec(j);
        if i <= j then begin
            swap(w[i], w[j]);
            inc(i);
            dec(j);
        end;
    until i > j;
    Quicksort3(i, r);
    Quicksort3(l, j);
end;

begin

    readln(n);
    for i := 1 to n do begin
        read(ch);
        s[i] := '';
        while ch <> ' ' do begin
            s[i] := s[i] + ch;
            read(ch);
        end;
        readln(a[i]);
    end;

    readln(m);
    for i := 1 to m do
        read(w[i]);
    for i := m + 1 to n do
        w[i] := 0;
    Quicksort3(1, n);
    readln;

    Quicksort(1, n);
    curr := a[1];
    pos := 1;
    for i := 2 to n do begin
        if curr <> a[i] then begin
            Quicksort2(pos, i - 1);
            pos := i;
            curr := a[i];
        end;
    end;
    Quicksort2(pos, n);

    readln(p);
    i := 1;
    while (i <= n) and (p <> s[i]) do
        inc(i);
    curr := i;

    //last
    mine := a[curr] + w[n];
    pos := curr;
    bal := n - 1;
    while (pos > 1) and (bal >= 1) do begin
        while ((a[pos - 1] + w[bal] > mine) or ((a[pos - 1] + w[bal] = mine) and (s[pos - 1] < p))) and (bal >= 1) do
            dec(bal);
        if bal >= 1 then begin
            dec(bal);
            dec(pos);
        end;
    end;
    write(pos, ' ');

    //last
    mine := a[curr] + w[1];
    pos := curr;
    bal := 2;
    while (pos < n) and (bal <= n) do begin
        while ((a[pos + 1] + w[bal] < mine) or ((a[pos + 1] + w[bal] = mine) and (s[pos + 1] > p))) and (bal <= n) do
            inc(bal);
        if bal <= n then begin
            inc(bal);
            inc(pos);
        end;
    end;
    write(pos);

end.