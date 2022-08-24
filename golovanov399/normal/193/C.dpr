program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

//it is a big shablon. if you see any strange function, never mind

const base = 1000000007;
 eps = 1e-8;
 inf = 1 shl 30;

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
 _1, _2, _3, _4, _5, _6, _7, _4567, _2367, _1357, _2345, _1346, _1256: integer;
 _23, _45, _67, _25, _34, _16, _15, _26, _37, _13, _46, _57: integer;
 l, r: integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(_4567, _2367, _1357);
 readln(_2345, _1346);
 readln(_1256);
 if (_2345 + _2367 + _4567) mod 2 = 1 then panic else
 begin
  _23 := (_2345 + _2367 - _4567) div 2;
  _45 := (_2345 - _2367 + _4567) div 2;
  _67 := (-_2345 + _2367 + _4567) div 2;
 end;
 if (_2345 + _1256 + _1346) mod 2 = 1 then panic else
 begin
  _25 := (_2345 + _1256 - _1346) div 2;
  _34 := (_2345 - _1256 + _1346) div 2;
  _16 := (-_2345 + _1256 + _1346) div 2;
 end;
 if (_1256 + _2367 + _1357) mod 2 = 1 then panic else
 begin
  _15 := (_1256 - _2367 + _1357) div 2;
  _26 := (_1256 + _2367 - _1357) div 2;
  _37 := (-_1256 + _2367 + _1357) div 2;
 end;
 if (_1346 + _1357 + _4567) mod 2 = 1 then panic else
 begin
  _13 := (_1346 + _1357 - _4567) div 2;
  _46 := (_1346 - _1357 + _4567) div 2;
  _57 := (-_1346 + _1357 + _4567) div 2;
 end;
 l := 0;
 r := 10000000;
 r := min(r, _13);
 r := min(r, _15);
 r := min(r, _16);
 l := max(l, _13 - _23);
 l := max(l, _15 - _25);
 l := max(l, _16 - _26);
 l := max(l, _13 - _34);
 l := max(l, _15 - _45);
 l := max(l, _16 - _46);
 l := max(l, _13 - _37);
 l := max(l, _15 - _57);
 l := max(l, _16 - _67);
 if r < l then panic else
 begin
  _1 := l;
  _3 := _13 - _1;
  _5 := _15 - _1;
  _6 := _16 - _1;
  _2 := _26 - _6;
  _4 := _46 - _6;
  _7 := _67 - _6;
  writeln(_1 + _2 + _3 + _4 + _5 + _6 + _7);
  for r := 1 to _1 + _2 + _3 + _4 + _5 + _6 + _7 do write('a');
  writeln;
  for r := 1 to _1 + _2 + _3 do write('a');
  for r := 1 to _4 + _5 + _6 + _7 do write('b');
  writeln;
  for r := 1 to _1 do write('a');
  for r := 1 to _2 + _3 do write('b');
  for r := 1 to _4 + _5 do write('a');
  for r := 1 to _6 + _7 do write('b');
  writeln;
  for r := 1 to _1 do write('b');
  for r := 1 to _2 do write('a');
  for r := 1 to _3 do write('b');
  for r := 1 to _4 do write('a');
  for r := 1 to _5 do write('b');
  for r := 1 to _6 do write('a');
  for r := 1 to _7 do write('b');
  writeln;
 end;
end.