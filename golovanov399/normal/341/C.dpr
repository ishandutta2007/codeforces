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

procedure panic;
begin
 writeln(-1);
 halt(0);
end;

var
 n, i, j, x: integer;
 a: array[-1..2013, 0..2013] of int64;
 b, bb: array[1..10000] of boolean;
 v: int64;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n);
 fillchar(b, sizeof(b), 0);
 for i := 1 to n do bb[i] := true;
 for i := 1 to n do
 begin
  read(x);
  if x = -1 then b[i] := true else bb[x] := false;
 end;
 a[0, 0] := 1;
 for i := 1 to n do a[0, i] := (a[0, i - 1] * i) mod base;
 for i := 1 to n do
 for j := 0 to n do
 begin
  if i + j <= n then
  begin
   v := a[i - 2, j + 1];
   v := v * (i - 1);
   a[i, j] := v;
   v := a[i - 1, j];
   v := v * j;
   a[i, j] := a[i, j] + v;
   a[i, j] := a[i, j] mod base;
  end else a[i, j] := 0;
 end;
 x := 0;
 j := 0;
 for i := 1 to n do
 if (b[i] and bb[i]) then inc(j) else
 if (b[i] or bb[i]) then inc(x);
 writeln(a[j, x div 2]);
(*
 writeln;
 for i := 0 to n do
 begin
  for j := 0 to n do write(a[i, j], ' ');
  writeln;
 end;
*)
end.