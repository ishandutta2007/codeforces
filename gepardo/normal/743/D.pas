{--------------------( alex256 )--------------------\
|    Contest: Codeforces Round 384 (Div. 2)         |
|       Task: D                                     |
|       Date: 14. 12. 2016                          |
\---------------------------------------------------}
program cf384D;

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
  Inf = 123456789012345678;
  
var
  ans: Int64 = -Inf;
  n, i, u, v: Integer;
  g: array [1 .. 300000] of TVectorInt;
  a: array [1 .. 300000] of Int64;
  dp, sz: array [1 .. 300000] of Int64;
  
procedure Swap(var a, b: Int64);
var t: Int64;
begin
  t := a; a := b; b := t;
end;
  
procedure Dfs(v: Integer; p: Integer = -1);
var
  u: Integer;
  max1, max2: Int64;
begin
  max1 := -Inf; 
  max2 := -Inf;
  sz[v] := a[v];
  dp[v] := -Inf;
  for u in g[v] do
    if u <> p
      then begin
        Dfs(u, v);    
        dp[v] := max(dp[v], dp[u]);
        sz[v] += sz[u];      
        if dp[u] > max2
          then max2 := dp[u];
        if max2 > max1 
          then Swap(max2, max1);
      end;
  dp[v] := max(dp[v], sz[v]);  
  if max2 <> -Inf
    then ans := max(ans, max1 + max2);    
end;
  
begin
  ReadLn(n);
  for i := 1 to n do 
    Read(a[i]);
  ReadLn;
  for i := 1 to n do
    g[i] := TVectorInt.Create;
  for i := 1 to n-1 do
  begin
    ReadLn(u, v);
    g[u].Add(v);
    g[v].Add(u);
  end;
  Dfs(1);
  if Ans = -Inf
    then WriteLn('Impossible')
    else WriteLn(Ans);   
  for i := 1 to n do
    g[i].Free;
end.