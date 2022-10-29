program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
    int = longint;

var
    a, b: array[1..3] of int;

begin

{$IFNDEF ONLINE_JUDGE}
    assign(input, 'input.txt');
    reset(input);
    assign(output, 'output.txt');
    rewrite(output);
{$ENDIF}

    read(a[1], a[2], a[3]);
    read(b[1], b[2], b[3]);
    if (a[1] <> b[1]) and (a[2] <> b[2]) and (a[3] <> b[3]) then
        write('NO')
    else
        write('YES');
    
{$IFNDEF ONLINE_JUDGE}
    close(input);
    close(output);
{$ENDIF}

end.