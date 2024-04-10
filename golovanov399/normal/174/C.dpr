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
 n, i, j, cnt, k: integer;
 a: array[0..100010] of integer;
 ans: array[1..100010, 1..2] of integer;
 st: array[0..100010] of integer;

procedure add(l, r: integer);
begin
 inc(cnt);
 ans[cnt, 1] := l;
 ans[cnt, 2] := r;
end;

begin
 cnt := 0;
 k := 0;
 st[0] := 0;
 a[0] := 0;
 readln(n);
 for i := 1 to n do
 read(a[i]);
 a[n + 1] := 0;
 inc(k);
 st[k] := 1;
 for i := 2 to n + 1 do
 begin
  if a[i] > a[i - 1] then
  begin
   inc(k);
   st[k] := i;
  end else
  if a[i] < a[i - 1] then
  begin
   while a[st[k - 1]] > a[i] do
   begin
    for j := a[st[k - 1]] + 1 to a[st[k]] do
    add(st[k], i - 1);
    dec(k);
   end;
   if a[st[k - 1]] < a[i] then
   begin
    for j := a[i] + 1 to a[st[k]] do add(st[k], i - 1);
    a[st[k]] := a[i];
   end else
   if a[st[k - 1]] = a[i] then
   begin
    for j := a[st[k - 1]] + 1 to a[st[k]] do
    add(st[k], i - 1);
    dec(k);
   end;
  end;
 end;
 writeln(cnt);
 for i := 1 to cnt do
 writeln(ans[i, 1], ' ', ans[i, 2]);
end.