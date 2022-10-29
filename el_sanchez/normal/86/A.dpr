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
    i, l, r: int64;
    k, maxx, sum: int64;

function weight(i: int64): int64;
var
    s: string;
    z: int;
    a, b: int64;
begin
    a := i;
    s := inttostr(i);
    b := 0;
    for z := 1 to length(s) do
        b := b * 10 + (9 - (ord(s[z]) - ord('0')));
    result := a * b;
end;

begin

{$IFNDEF ONLINE_JUDGE}
    assign(input, 'input.txt');
    reset(input);
    assign(output, 'output.txt');
    rewrite(output);
{$ENDIF}

    sum := -1;
    read(l, r);
    k := 1;
    {i := l;
    while i <= r do begin
        k := weight(i);
        if k > sum then begin
            maxx := i;
            sum := k;
        end;
        inc(i);
    end;
    write(maxx, ' ', sum);  
    }

    while k < r do
        k := k * 10;
    if k = r then
        write(weight(k))
    else begin
        if k div 2 > r then
            write(weight(r))
        else begin
            if k div 2 >= l then
                write(weight(k div 2))
            else
                write(weight(l));
        end;
    end;

{$IFNDEF ONLINE_JUDGE}
    close(input);
    close(output);
{$ENDIF}

end.