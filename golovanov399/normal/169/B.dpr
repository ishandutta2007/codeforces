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
 s, t: string;
 n, m, i, j: integer;
 a: array[0..9] of integer;
 flag: boolean;

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
 readln(s);
 readln(t);
 fillchar(a, sizeof(a), 0);
 n := length(s);
 m := length(t);
 for i := 1 to m do
 inc(a[ord(t[i]) - 48]);
 for i := 1 to n do
 begin
  flag := false;
  for j := 9 downto ord(s[i]) - 47 do
  begin
   if (a[j] > 0) and (not flag) then
   begin
    dec(a[j]);
    write(j);
    flag := true;
   end;
  end;
  if not flag then
  write(s[i]);
 end;
end.