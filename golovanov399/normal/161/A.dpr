program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

type
 TArray = array[1..100000] of integer;

procedure swap(var x, y: integer);
var
 z: integer;
begin
 z := x;
 x := y;
 y := z;
end;

procedure QSort(var a: TArray; l, r: integer);
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
 QSort(a, l, j);
 QSort(a, i, r);
end;

var
 n, m, i, j, x, y, cnt: integer;
 a, b, c: TArray;

begin
 readln(n, m, x, y);
 for i := 1 to n do
 read(a[i]);
 for j := 1 to m do
 read(b[j]);
 fillchar(c, sizeof(c), 0);
 i := 1;
 cnt := 0;
 for j := 1 to m do
 begin
  while (i <= n) and (a[i] + y < b[j]) do inc(i);
  if (i <= n) and (a[i] - x <= b[j]) then
  begin
   inc(cnt);
   c[i] := j;
   inc(i);
  end;
 end;
 writeln(cnt);
 for i := 1 to n do
 if c[i] > 0 then writeln(i, ' ', c[i]);
end.