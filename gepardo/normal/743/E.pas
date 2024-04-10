{--------------------( alex256 )--------------------\
|    Contest: Codeforces Round 384 (Div. 2)         |
|       Task: E                                     |
|       Date: 14. 12. 2016                          |
\---------------------------------------------------}
program cf384E;

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

const
  inf = 123456789;

var
  n: Integer;
  a: array [1 .. 2000] of Integer;
  dp: array [0 .. 255, 1 .. 8, 0 .. 255] of Integer;
  pcnt: array [1 .. 2000, 1 .. 8, 0 .. 150] of Integer;
  i, j, k, l, m, lc, q, shll: Integer;
  ans: Integer = 0;
  popcnt: array [0 .. 255] of Integer;

begin
  for i := 0 to 255 do
    for j := 0 to 7 do
      if (i and (1 shl j)) <> 0
        then Inc(popcnt[i]);       
  ReadLn(n);
  for i := 1 to n do Read(a[i]);
  ReadLn;
  for i := 1 to n+1 do
    for j := 1 to 8 do 
    begin
      pcnt[i, j, 0] := i;
      k := 0;
      for l := i to n do
        if a[l] = j
          then begin
            Inc(k);
            pcnt[i, j, k] := l+1;         
          end;
      for l := k+1 to 150 do
        pcnt[i, j, l] := inf;
    end;
  for i := 0 to 149 do
  begin
    for j := 0 to 255 do
	  for k := 1 to 8 do
		for l := 0 to 255 do
		  dp[j, k, l] := inf;
	dp[0, 1, 0] := 1;	   
    for j := 1 to 255 do
	  for k := 1 to 8 do
		for l := 0 to 255 do
	    begin
	      shll := 1 shl (k-1);
	      if (j and shll) = 0 then Continue; 
	      if (j or l) <> j then Continue;
	      if (l and shll) = 0
	        then lc := l
	        else lc := l xor shll;
	      q := inf;
	      for m := 1 to 8 do
	        q := min(q, dp[j xor shll, m, lc]);
	      if q <> inf
	        then begin
	          if (l and shll) = 0
	            then dp[j, k, l] := pcnt[q, k, i]
	            else dp[j, k, l] := pcnt[q, k, i + 1];
	        end;
	    end;
	for j := 1 to 8 do
	  for k := 0 to 255 do
	    if dp[255, j, k] <> inf
	      then ans := max(ans, i * 8 + popcnt[k]);
  end; 
  WriteLn(ans);
end.