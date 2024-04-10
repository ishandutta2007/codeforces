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
    i, k, n: int;
    Arr: Array[1..MaxN] of int;

begin

{$IFNDEF ONLINE_JUDGE}
    assign(input, 'input.txt');
    reset(input);
    assign(output, 'output.txt');
    rewrite(output);
{$ENDIF}

    read(n);
    case n of
    1: begin writeln('a'); writeln('a');writeln('c');writeln('c'); end;
    2: begin
        writeln('aa'); writeln('bb');writeln('cc');writeln('dd');
    end;
    else begin
        if not odd(n) then begin
            i := 1;
            while (i + 3) <= n do begin
                write('aabb');
                i := i + 4;
            end;
            if i < n then
                write('aa');
            writeln;
            write('x');
            i := 2;
            while (i + 3) <= n do begin
                write('ccdd');
                i := i + 4;
            end;
            if i < n then
                write('cc');
            write('x');
            writeln;
            write('x');
            i := 2;
            while (i + 3) <= n do begin
                write('aabb');
                i := i + 4;
            end;
            if i < n then
                write('aa');
            write('x');
            writeln;
            i := 1;
            while (i + 3) <= n do begin
                write('ccdd');
                i := i + 4;
            end;
            if i < n then
                write('cc');
            writeln;
        end else begin
            i := 1;
            while (i + 3) <= n do begin
                write('aabb');
                i := i + 4;
            end;
            if i < n then
                write('aa');
            writeln('x');
            i := 1;
            while (i + 3) <= n do begin
                write('ccdd');
                i := i + 4;
            end;
            if i < n then
                write('cc');
            writeln('x');
            write('y');
            i := 2;
            while (i + 3) <= n do begin
                write('aabb');
                i := i + 4;
            end;
            if i < n then
                write('aa');
            writeln;
            write('y');
            i := 1;
            while (i + 3) <= n do begin
                write('ccdd');
                i := i + 4;
            end;
            if i < n then
                write('cc');
        end;
    end;
    end;

{$IFNDEF ONLINE_JUDGE}
    close(input);
    close(output);
{$ENDIF}

end.