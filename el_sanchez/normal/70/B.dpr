program solution;

{$APPTYPE CONSOLE}

uses
    SysUtils, Math;

const
    MaxN = 100000;

type
    int = longint;

var
    s: string;
    i, cur, n, snt, len, msg: int;
    lens: Array[1..MaxN] of int;

begin

    readln(n);
    readln(s);
    s := s + ' ';
    len := length(s);
    cur := 0;
    snt := 0;
    i := 1;
    while i <= len do begin
        if s[i] in ['.', '?', '!'] then begin
            inc(snt);
            lens[snt] := cur + 1;
            if lens[snt] > n then begin
                writeln('Impossible');
                halt;
            end;
            cur := 0;
            i := i + 2;
        end else begin
            inc(cur);
            inc(i);
        end;
    end;

    msg := 0;
    cur := lens[1];
    for i := 2 to snt do begin
        if cur + lens[i] + 1 > n then begin
            inc(msg);
            cur := lens[i];
        end else
            cur := cur + lens[i] + 1;
    end;

    if cur > 0 then
        inc(msg);

    write(msg);

end.