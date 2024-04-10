program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

type
 TArray = array[1..50] of integer;

procedure swap(var x, y: integer);
var
 z: integer;
begin
 z := x;
 x := y;
 y := z;
end;

var
 n, i, k, c, x, y: integer;
 a: TArray;


procedure QSort(l, r: integer);
var
 i, j, x: integer;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := a[l + random(r - l + 1)];
 repeat
  while (a[i] > x) do inc(i);
  while (a[j] < x) do dec(j);
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
 readln(n, k);
 for i := 1 to n do
 begin
  readln(x, y);
  a[i] := x * 51 + 50 - y;
 end;
 QSort(1, n);
 i := k;
 while (i > 1) and (a[i] = a[i - 1]) do dec(i);
 c := 1;
//   , 
 while (i < n) and (a[i] = a[i + 1]) do
 begin
  inc(i);
  inc(c);
 end;
 writeln(c);
end.