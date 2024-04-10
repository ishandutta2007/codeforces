{$M 16777216}
program solution;

{$APPTYPE CONSOLE}

uses
    SysUtils, Math;

const
    MaxN = 200;

type
    int = longint;

var
    i, j, l, k, n, card: int;
    elem: int;
    use: array[1..MaxN] of boolean;
    t: array[1..MaxN] of int;
    s: Array[1..MaxN, 1..MaxN] of int;

begin

{$IFNDEF ONLINE_JUDGE}
    assign(input, 'input.txt');
    reset(input);
    assign(output, 'output.txt');
    rewrite(output);
{$ENDIF}

    fillchar(s, sizeof(s), 0);
    fillchar(use, sizeof(use), 0);
    read(n);
    if n = 2 then begin
        read(k);
        read(j);
        writeln('1 ', j);
        write(k-1);
        for i := 1 to k-1 do begin
            read(j);
            write(' ', j);
        end;
        halt;
    end;
    card := n * (n - 1) div 2;
    for i := 1 to card do begin
        read(k);
        for j := 1 to k do
            read(t[j]);
        for j := 1 to k do
            for l := 1 to k do
                if j <> l then begin
                    inc(s[t[j], t[l]]);
                    inc(s[t[l], t[j]]);
                end;
    end;

    for i := 1 to MaxN do begin
        elem := 0;
        for j := 1 to MaxN do
            if s[i, j] <> 0 then
                inc(elem);
        if elem = 0 then
            use[i] := true;
    end;

    for i := 1 to MaxN do begin
        if not use[i] then begin
            use[i] := true;
            elem := 0;
            for j := 1 to MaxN do
                if s[i, j] = (n-1)*2 then begin
                    inc(elem);
                    use[j] := true;
                end;
            write(elem+1, ' ', i);
            for j := 1 to MaxN do
                if s[i, j] = (n-1)*2 then
                    write(' ', j);
            writeln;
        end;
    end;         

{$IFNDEF ONLINE_JUDGE}
    close(input);
    close(output);
{$ENDIF}

end.