program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

type
 TArray = array[0..100010] of integer;
 int53 = int64;
 edge = record
  x, y: integer;
 end;

procedure swap(var x, y: integer);
var
 z: integer;
begin
 z := x;
 x := y;
 y := z;
end;

var
 n, i, x, k, cnt: integer;
 a: array[1..510] of integer;
 b: boolean;

procedure QSort(l, r: integer);
var
 i, j, x: integer;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := a[l + random(r - l + 1)];
 repeat
  while a[i] < x do inc(i);
  while a[j] > x do dec(j);
  if i <= j then
  begin
   swap(a[i], a[j]);
   inc(i);
   dec(j);
  end;
 until i > j;
 QSort(l, j);
 QSort(i, r);
end;

begin
 randomize;
 readln(n, x);
 b := false;
 for i := 1 to n do
 begin
  read(a[i]);
  b := b or (a[i] = x);
 end;
 cnt := 0;
 if not b then
 begin
  inc(n);
  a[n] := x;
  inc(cnt);
 end;
 QSort(1, n);
 k := (n + 1) div 2;
 if a[k] = x then
 begin
  writeln(cnt);
  halt(0);
 end else
 if a[k] > x then
 begin
  cnt := cnt - (n mod 2);
  while a[k] > x do
  begin
   dec(k);
   inc(cnt, 2);
  end;
 end else
 begin
  cnt := cnt - 1 + (n mod 2);
  while a[k] < x do
  begin
   inc(k);
   inc(cnt, 2);
  end;
 end;
 writeln(cnt);
end.