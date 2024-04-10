program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

type
 TArray = array[1..100000] of integer;
 int53 = int64;

procedure swap(var x, y: integer);
var
 z: integer;
begin
 z := x;
 x := y;
 y := z;
end;

var
 n, i, j, k: integer;
 a, b: array[1..500] of integer;
 boo: array[1..4] of boolean;
{
procedure QSort(l, r: integer);
var
 i, j, x: integer;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := l + random(r - l + 1);
 repeat
  while (tp[i] < tp[x]) or ((tp[i] = tp[x]) and (a[i] < a[x])) do inc(i);
  while (tp[j] > tp[x]) or ((tp[j] = tp[x]) and (a[j] > a[x])) do dec(j);
  if i <= j then
  begin
   swap(a[i], a[j]);
   swap(tp[i], tp[j]);
   swap(num[i], num[j]);
   inc(i);
   dec(j);
  end;
 until i > j;
 QSort(l, j);
 QSort(i, r);
end;
}
begin
 randomize;
 readln(n);
 for i := 1 to n do
 read(a[i], b[i]);
 k := 0;
 for i := 1 to n do
 begin
  fillchar(boo, sizeof(boo), 0);
  for j := 1 to n do
  if (a[j] < a[i]) and (b[j] = b[i]) then boo[1] := true else
  if (a[j] > a[i]) and (b[j] = b[i]) then boo[2] := true else
  if (a[j] = a[i]) and (b[j] < b[i]) then boo[3] := true else
  if (a[j] = a[i]) and (b[j] > b[i]) then boo[4] := true;
  if (boo[1]) and (boo[2]) and (boo[3]) and (boo[4]) then inc(k);
 end;
 writeln(k);
end.