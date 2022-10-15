{--------------------( alex256 )--------------------\
|    Contest: Codeforces Round 353 (Div. ?)         |
|       Task: C                                     |
|       Date: 16. 05. 2016                          |
\---------------------------------------------------}
program cf353C;

{$mode objfpc}{$H+}{$coperators on}

uses
  SysUtils, Math, FGL;

type
  TVectorInt64 = specialize TFPGList<Int64>;    

function CmpInt64(const A, B: Int64): Integer;
begin
  if A < B then Result := -1;
  if A = B then Result := 0;
  if A > B then Result := 1;
end;                           

var
  N, I, BI: Integer;
  P: TVectorInt64;
  A: Array [1 .. 1000000] of Integer; 
  G: Integer = 1;

begin
  P := TVectorInt64.Create; 
  ReadLn(N);
  P.Capacity := N + 1;
  for I := 1 to N do Read(A[I]);
  P.Add(0);
  for I := 1 to N - 1 do P.Add(P.Items[I - 1] + A[I]);
  P.Sort(@CmpInt64);
  I := 0;
  while I < P.Count do
  begin
    BI := I;
    while (I < P.Count) and (P.Items[BI] = P.Items[I]) do Inc(I);
    Dec(I);
    G := Max(G, I - BI + 1);
    Inc(I);
  end;
  WriteLn(N - G);
  P.Free;
end.