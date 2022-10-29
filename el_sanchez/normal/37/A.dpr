program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
    int = longint;

var
    dlin: array[1..1000] of int;
    max1, max2, i, k, n: int;

begin

{$IFNDEF ONLINE_JUDGE}
    assign(input, 'input.txt');
    reset(input);
    assign(output, 'output.txt');
    rewrite(output);
{$ENDIF}

    fillchar(dlin, sizeof(dlin), 0);
    max1 := 0;
    max2 := 0;
    read(n);
    for i := 1 to n do begin
        read(k);
        inc(dlin[k]);
    end;
    for i := 1 to 1000 do begin
        if dlin[i] > 0 then begin
            inc(max2);
            if max1 < dlin[i] then
                max1 := dlin[i];
        end;
    end;
    write(max1, ' ', max2);
    
{$IFNDEF ONLINE_JUDGE}
    close(input);
    close(output);
{$ENDIF}

end.