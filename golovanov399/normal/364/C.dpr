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
 n: integer;
 i: integer;
 p: array[1..12] of integer;
 j, k: integer;
 flag: boolean;
 cnt: integer;
 a: array[1..100000] of integer;
 v: integer;

procedure QSort(l, r: integer);
var
 i, j, x: integer;
begin
 if (l >= r) then exit;
 i := l;
 j := r;
 x := a[l + random(r - l + 1)];
 repeat
  while (a[i] < x) do inc(i);
  while (a[j] > x) do dec(j);
  if (i <= j) then
  begin
   swap(a[i], a[j]);
   inc(i);
   dec(j);
  end;
 until (i > j);
 QSort(l, j);
 QSort(i, r);
end;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n);
 p[1] := 2;
 p[2] := 3;
 p[3] := 5;
 p[4] := 7;
 p[5] := 11;
 p[6] := 13;
 p[7] := 17;
 p[8] := 19;
 p[9] := 23;
 p[10] := 29;
 p[11] := 31;
 p[12] := 37;
 for k := 2 to 12 do
 begin
  v := 1;
  cnt := 0;
  i := k;
  while (i > 0) do
  begin
   if (i = k) then
   begin
    if v <= 2 * n * n then
    begin
     inc(cnt);
     a[cnt] := v;
     v := v * p[i];
    end else
    begin
     while v mod p[i] = 0 do v := v div p[i];
     dec(i);
    end;
   end else
   begin
    if (v > 2 * n * n) then
    begin
     while v mod p[i] = 0 do v := v div p[i];
     dec(i);
    end else
    begin
     v := v * p[i];
     i := k;
    end;
   end;
  end;
  if (cnt >= n) then
  begin
   randomize;
   QSort(1, cnt);
   for i := cnt downto cnt - n + 1 do write(a[i], ' ');
   halt(0);
  end;
 end;
end.