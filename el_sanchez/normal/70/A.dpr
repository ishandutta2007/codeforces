program solution;

{$APPTYPE CONSOLE}

uses
    SysUtils, Math;

const
    MaxN = 1000;

type
    int = longint;

var
    i, k, n, ans: int;
    Arr: Array[0..MaxN] of int;

begin

    read(n);
    if n < 2 then
        write(1)
    else begin
        ans := 1;
        for i := 2 to n do
            ans := (ans * 3) mod 1000003;
        write(ans);
    end;


end.