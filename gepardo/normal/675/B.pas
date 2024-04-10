{--------------------( alex256 )--------------------\
|    Contest: Codeforces Round 353 (Div. ?)         |
|       Task: B                                     |
|       Date: 16. 05. 2016                          |
\---------------------------------------------------}
program cf000Q;

{$mode objfpc}{$H+}{$coperators on}

uses
  SysUtils, Math, FGL;

type
  TVectorInt = specialize TFPGList<Integer>;    

function CmpInt(const A, B: Integer): Integer;
begin
  Result := A - B;
end;

function GetChar: Char;
begin
  Result := #0;
  while Result < ' ' do Read(Result);
end;

var
  a, b, c, d, n, i, w, x, y, z: integer;
  ans: int64 = 0;

begin
  readln(n, a, b, c, d);
  for i := 1 to n do
  begin
    w := i;
    x := w + b - c;
    y := w + a - d;
    z := y + b - c;
    if (w < 1) or (w > n) or (x < 1) or (x > n) or
       (y < 1) or (y > n) or (z < 1) or (z > n)
      then Continue;
    ans += n; 
  end;
  write(ans);
end.