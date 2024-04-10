{$M 16777216}
program solution;

{$APPTYPE CONSOLE}

uses
    SysUtils, Math;

const
    MaxN = 200000;

type
    int = longint;

var
    ch: char;
    i, k, n: int;
    st: Array[1..MaxN] of char;

begin

{$IFNDEF ONLINE_JUDGE}
    assign(input, 'input.txt');
    reset(input);
    assign(output, 'output.txt');
    rewrite(output);
{$ENDIF}

    n := 0;
    while not eoln do begin
        read(ch);
        if (n=0) or (st[n] <> ch) then begin
            inc(n);
            st[n] := ch;
        end else begin
            if st[n] = ch then
                dec(n);
        end;
    end;
    for i := 1 to n do
        write(st[i]);        

{$IFNDEF ONLINE_JUDGE}
    close(input);
    close(output);
{$ENDIF}

end.