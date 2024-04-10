{--------------------( alex256 )--------------------\
|    Contest: Codeforces Round 384 (Div. 2)         |
|       Task: A                                     |
|       Date: 14. 12. 2016                          |
\---------------------------------------------------}
program cf384A;

{$mode objfpc}{$H+}{$coperators on}

uses
  SysUtils, Math, FGL;

type
  TVectorInt = specialize TFPGList<Integer>;   
  TVectorLL  = specialize TFPGList<Int64>;

function CmpInt(const A, B: Integer): Integer;
begin
  Result := A - B;
end;

function CmpInt64(const A, B: Int64): Int64;
begin
  Result := A - B;
end;

function GetChar: Char;
begin
  Result := #0;
  while Result < ' ' do Read(Result);
end;

var
  n, a, b: Integer;
  s: String;

begin
  ReadLn(n, a, b);
  ReadLn(s);
  if s[a] = s[b]
    then WriteLn(0)
    else WriteLn(1);
end.