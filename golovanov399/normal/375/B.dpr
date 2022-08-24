program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}
{$O-}

uses
  SysUtils,
  Math;

//it is a big shablon. if you see any strange function, never mind

const base = 1000000007;
 eps = 1e-8;
 inf = 1 shl 30;
 trye = true;

type
 TArray = array[0..10000010] of integer;
 int53 = int64;
 itneger = integer;
 point = record
  x, y: integer;
 end;

function sqrr(a, b: int64): int64;
var
 dega, res: int64;
begin
 res := 1;
 dega := a;
 while b > 0 do
 begin
  if odd(b) then res := res * dega;
  dega := dega * dega;
  b := b div 2;
  res := res mod base;
  dega := dega mod base;
 end;
 result := res mod base;
end;

function less(x, y: point): boolean;
begin
 if (x.x < y.x) or ((x.x = y.x) and (x.y < y.y)) then result := true else result := false;
end;

procedure swap(var x, y: integer);
var
 z: integer;
begin
 z := x;
 x := y;
 y := z;
end;

procedure swap64(var x, y: int64);
var
 z: int64;
begin
 z := x;
 x := y;
 y := z;
end;

procedure swapex(var x, y: extended);
var
 z: extended;
begin
 z := x;
 x := y;
 y := z;
end;

procedure swapp(var x, y: point);
var
 z: point;
begin
 z := x;
 x := y;
 y := z;
end;

function gcd(x, y: integer): integer;
begin
 while ((x > 0) and (y > 0)) do
 begin
  if x > y then x := x mod y else y := y mod x;
 end;
 result := x + y;
end;

function nok(x, y: integer): int64;
var
 v: int64;
begin
 v := x;
 v := v * y;
 v := v div gcd(x, y);
 result := v;
end;

procedure panic;
begin
 writeln(-1);
 halt(0);
end;

var
 n, m: integer;
 c: array[1..5000, 1..5000] of char;
 i, j, k: integer;
 d: array[1..5000, 0..5010] of integer;
 p: array[0..5010] of integer;
 pp, ppp: integer;
 ans: integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m);
 for i := 1 to n do
 begin
  for j := 1 to m do read(c[i, j]);
  readln;
 end;
 for i := 1 to n do d[i][0] := 0;
 for i := 1 to n do
 begin
  j := 1;
  while (j <= m) do
  begin
   while ((j <= m) and (c[i][j] = '0')) do
   begin
    d[i][j] := 0;
    inc(j);
   end;
   if (j <= m) then
   begin
    d[i][j] := 1;
    while ((j + d[i][j] - 1 < m) and (c[i][j + d[i][j]] = '1')) do inc(d[i][j]);
    while (d[i][j] > 0) do
    begin
     d[i][j + 1] := d[i][j] - 1;
     inc(j);
    end;
   end;
  end;
 end;
 ans := 0;
 ppp := 1;
 for i := 1 to m do p[i] := 0;
 for i := 1 to m do
 begin
  pp := ppp;
  ppp := pp + 1;
  for j := 1 to n do if p[d[j][i]] <= pp then p[d[j][i]] := pp + 1 else
  begin
   inc(p[d[j][i]]);
   inc(ppp);
  end;
  k := 0;
  for j := m - i + 1 downto 1 do
  begin
   if p[j] > pp then k := k + p[j] - pp;
   if (k * j > ans) then ans := k * j;
  end;
 end;
 writeln(ans);
end.