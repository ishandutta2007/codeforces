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
    i, cola, step, n, name: int64;

begin

{$IFNDEF ONLINE_JUDGE}
    assign(input, 'input.txt');
    reset(input);
    assign(output, 'output.txt');
    rewrite(output);
{$ENDIF}

    read(n);
    cola := 1;
    step := 1;
    name := 0;
    while cola + step*5 <= n do begin
        cola := cola + step*5;
        step := step * 2;
    end;
    dec(cola);
    while cola < n do begin
        cola := cola + step;
        inc(name);
    end;
    case name of
    1: write('Sheldon');
    2: write('Leonard');
    3: write('Penny');
    4: write('Rajesh');
    5: write('Howard');
    end;

{$IFNDEF ONLINE_JUDGE}
    close(input);
    close(output);
{$ENDIF}

end.