{--------------------( alex256 )--------------------\
|    Contest: Codeforces Round 384 (Div. 2)         |
|       Task: B                                     |
|       Date: 14. 12. 2016                          |
\---------------------------------------------------}
program cf384B;

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

function Get(n, k: Int64): Int64;
var
  q: Int64;
begin
  q := Int64(1) shl n;
  if q = k
    then Exit(n + 1)
    else if k > q
           then Exit(Get(n - 1, k - q))
           else Exit(Get(n - 1, k))
end;

var
  n, k: Int64;
  
begin
  ReadLn(n, k);
  WriteLn(Get(n, k));
end.