{--------------------( alex256 )--------------------\
|    Contest: Codeforces Round 353 (Div. 2)         |
|       Task: A                                     |
|       Date: 16. 05. 2016                          |
\---------------------------------------------------}
program cf353A;

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

var a, b, c: Integer;

begin
  ReadLn(a, b, c);
  if a = b then begin Write('YES'); Exit End;
  if c = 0 then begin Write('NO'); Exit End;
  if c < 0
    then begin
           a := -a;
           b := -b;
         end;
  if a > b then begin Write('NO'); Exit end;
  b -= a;
  if b mod c <> 0 
    then Write('NO')
    else Write('YES');
end.