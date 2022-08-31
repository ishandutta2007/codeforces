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
 n, i, x, qq, ww, ee: integer;
 a: array[1..7] of integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n);
 fillchar(a, sizeof(a), 0);
 for i := 1 to n do
 begin
  read(x);
  inc(a[x]);
 end;
 if a[7] > 0 then panic;
 if a[5] > 0 then panic;
 ee := a[4];
 if a[2] < ee then panic else a[2] := a[2] - ee;
 if a[1] < ee then panic else a[1] := a[1] - ee;
 qq := a[3];
 ww := a[2];
 if a[1] <> qq + ww then panic;
 if a[6] <> qq + ww then panic;
 for i := 1 to qq do writeln('1 3 6');
 for i := 1 to ww do writeln('1 2 6');
 for i := 1 to ee do writeln('1 2 4');
end.