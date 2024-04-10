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
 n, m, i, j, k, x, y, z, t: integer;
 a: array[0..51, 0..51] of char;
 b: array[1..50, 1..50] of integer;
 boo: array[1..50, 1..50] of boolean;
 cnt: integer;

procedure dfs(x, y: integer);
begin
 inc(k);
 boo[x, y] := true;
 if (a[x - 1, y] = '#') and (boo[x - 1, y] = false) then dfs(x - 1, y);
 if (a[x + 1, y] = '#') and (boo[x + 1, y] = false) then dfs(x + 1, y);
 if (a[x, y - 1] = '#') and (boo[x, y - 1] = false) then dfs(x, y - 1);
 if (a[x, y + 1] = '#') and (boo[x, y + 1] = false) then dfs(x, y + 1);
end;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m);
 for i := 0 to 51 do
 for j := 0 to 51 do
 a[i, j] := '.';
 for i := 1 to n do
 begin
  for j := 1 to m do
  read(a[i, j]);
  readln;
 end;
 fillchar(b, sizeof(b), 0);
 cnt := 0;
 for i := 1 to n do
 for j := 1 to m do
 if a[i, j] = '#' then
 begin
  inc(cnt);
  b[i, j] := ((ord(a[i - 1, j]) + ord(a[i + 1, j]) + ord(a[i, j - 1]) + ord(a[i, j + 1])) - 4 * ord('.')) div (ord('#') - ord('.'));
 end;
 k := 5;
 for i := 1 to n do
 for j := 1 to m do
 if (b[i, j] > 0) and (b[i, j] < k) and (b[i, j] + 1 < cnt) then k := b[i, j];
 if k = 5 then panic else
 if k = 1 then writeln(k) else
 begin
  x := 1;
  y := 1;
  for i := 1 to n do
  for j := 1 to m do
  if a[i, j] = '#' then
  begin
   x := i;
   y := j;
  end;
  z := 1;
  t := 1;
  for i := n downto 1 do
  for j := m downto 1 do
  if a[i, j] = '#' then
  begin
   z := i;
   t := j;
  end;
  for i := 1 to n do
  for j := 1 to m do
  if a[i, j] = '#' then
  begin
   k := 0;
   fillchar(boo, sizeof(boo), 0);
   a[i, j] := '.';
   if (i = x) and (j = y) then dfs(z, t) else dfs(x, y);
   if k < cnt - 1 then
   begin
    writeln(1);
    halt(0);
   end;
   a[i, j] := '#';
  end;
  writeln(2);
 end;
end.