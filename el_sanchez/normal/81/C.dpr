{$M 16777216}
program solution;

{$APPTYPE CONSOLE}

uses
    SysUtils, Math;

const
    MaxN = 100000;

type
    int = longint;

var
    i, k, a, b, n: int;
    f: Array[1..MaxN] of boolean;
    num: Array[1..MaxN] of int;

begin

{$IFNDEF ONLINE_JUDGE}
    assign(input, 'input.txt');
    reset(input);
    assign(output, 'output.txt');
    rewrite(output);
{$ENDIF}

    fillchar(f, sizeof(f), 0);
    read(n, a, b);
    for i := 1 to n do
        read(num[i]);

    if a < b then begin
        for k := 5 downto 1 do begin
            i := 1;
            while (a >= 1) and (i <= n) do begin
                if num[i] = k then begin
                    f[i] := true;
                    dec(a);
                end;
                inc(i);
            end;
        end;
        for i := 1 to n do
            if f[i] then
                write('1 ')
            else
                write('2 ');
        halt;
    end;
    if a > b then begin
        for k := 5 downto 1 do begin
            i := n;
            while (b >= 1) and (i >= 1) do begin
                if num[i] = k then begin
                    f[i] := true;
                    dec(b);
                end;
                dec(i);
            end;
        end;
        for i := 1 to n do
            if f[i] then
                write('2 ')
            else
                write('1 ');
        halt;
    end;
    if a = b then begin
        for i := 1 to a do
            write('1 ');
        for i := 1 to b do
            write('2 ');
    end;

{$IFNDEF ONLINE_JUDGE}
    close(input);
    close(output);
{$ENDIF}

end.