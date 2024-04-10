program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

const base = 1000000007;
 eps = 1e-8;

type
 TArray = array[0..1000010] of integer;
 int53 = int64;
 itneger = integer;
 point = record
  x, y: integer;
 end;

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
  while (m[i] > m[x]) or ((m[i] = m[x]) and (v[i] > v[x])) do inc(i);
  while (m[j] < m[x]) or ((m[j] = m[x]) and (v[j] < v[x])) do dec(j);
  if i <= j then
  begin
   swap(m[i], m[j]);
   swap(v[i], v[j]);
   swap(num[i], num[j]);
   inc(i);
   dec(j);
  end;
 until i > j;
 QSort(l, j);
 QSort(i, r);
end;
*)

var
 n, m, k, a, b, i, x, y: integer;
 s, t: string;

procedure duel(x, y: char; var xx, yy: integer);
begin
 if x = y then exit;
 if ((x = 'R') and (y = 'S')) or ((x = 'S') and (y = 'P')) or ((x = 'P') and (y = 'R')) then inc(yy) else
 inc(xx);
end;

begin
 readln(n);
 readln(s);
 readln(t);
 m := length(s);
 k := length(t);
 x := 0;
 y := 0;
 for i := 1 to (m * k) do
 duel(s[(i - 1) mod m + 1], t[(i - 1) mod k + 1], x, y);
 a := x * (n div (m * k));
 b := y * (n div (m * k));
 n := n mod (m * k);
 for i := 1 to n do
 duel(s[(i - 1) mod m + 1], t[(i - 1) mod k + 1], a, b);
 writeln(a, ' ', b);
end.