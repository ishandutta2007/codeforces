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
 n, m, i, j: integer;
 a: array[1..3] of point;
 cnt: integer;
 c: char;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input,'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m);
 cnt := 0;
 for i := 1 to n do
 begin
  for j := 1 to m do
  begin
   read(c);
   if (c = '*') then
   begin
    inc(cnt);
    a[cnt].x := i;
    a[cnt].y := j;
   end;
  end;
  readln;
 end;
 if a[1].x = a[2].x then i := a[1].x else i := a[3].x;
 if a[1].y = a[2].y then j := a[1].y else j := a[3].y;
 writeln(a[1].x + a[2].x + a[3].x - 2 * i, ' ', a[1].y + a[2].y + a[3].y - 2 * j);
end.