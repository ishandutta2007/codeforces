program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

const base = 1000000007;

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

function sqrr(a, b: integer): int64;
var dega, res: int64;
begin
 dega := a;
 res := 1;
 while b > 0 do
 begin
  if odd(b) then
  res := res * dega mod base;
  dega := dega * dega mod base;
  b := b div 2;
 end;
 result := res mod base;
end;

var
 n: integer;
 vsp: int64;
(*
procedure QSort(l, r: integer);
var
 i, j, x: integer;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := l + random(r - l + 1);
 repeat
  while (a[i] < a[x]){ or ((p[i] = p[x]) and (t[i] > t[x]))} do inc(i);
  while (a[j] > a[x]){ or ((p[j] = p[x]) and (t[j] < t[x]))} do dec(j);
  if i <= j then
  begin
   swap(a[i], a[j]);
//   swap(t[i], t[j]);
   inc(i);
   dec(j);
  end;
 until i > j;
 QSort(l, j);
 QSort(i, r);
end;
*)
begin
// randomize;
 readln(n);
 vsp := sqrr(3, n);
 if odd(n) then vsp := vsp - 3 else vsp := vsp + 3;
 vsp := vsp * sqrr(4, base - 2) mod base;
 writeln(vsp);
end.