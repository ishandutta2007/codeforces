program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

const base = 1000000007;

type
 TArray = array[0..1000010] of integer;
 int53 = int64;

function sqrr(a, b: integer): int64;
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

procedure swap(var x, y: integer);
var
 z: integer;
begin
 z := x;
 x := y;
 y := z;
end;

var
 n, a, b, i, j: integer;
 ar: array[1..2000] of integer;

(*
procedure QSort(l, r: integer);
var
 i, j, x: integer;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := a[l + random(r - l + 1)];
 repeat
  while (a[i] < x) do inc(i);
  while (a[j] > x) do dec(j);
  if i <= j then
  begin
   swap(a[i], a[j]);
   swapx(b[i], b[j]);
   inc(i);
   dec(j);
  end;
 until i > j;
 QSort(l, j);
 QSort(i, r);
end;
*)

begin
 readln(n, a, b);
 for i := 1 to n do
 read(ar[i]);
 for i := 1 to n - 1 do
 for j := i + 1 to n do
 if ar[i] > ar[j] then swap(ar[i], ar[j]);
 writeln(ar[b + 1] - ar[b]);
end.