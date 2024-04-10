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
 n, k, l, r, n1, m, i: integer;
 dg: array[1..100] of integer;
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
 readln(n, k);
 m := 1;
 dg[1] := 1;
 while (1000000000 / k >= dg[m]) do
 begin
  inc(m);
  dg[m] := dg[m - 1] * k;
 end;
 inc(m);
 dg[m] := 1000000001;
 l := 1;
 r := n;
 while (r - l > 1) do
 begin
  n1 := 0;
  m := (l + r) div 2;
  i := 1;
  while m div dg[i] > 0 do
  begin
   n1 := n1 + m div dg[i];
   inc(i);
  end;
  if n1 < n then l := m else r := m;
 end;
 n1 := 0;
 m := (l + r) div 2;
 i := 1;
 while m div dg[i] > 0 do
 begin
  n1 := n1 + m div dg[i];
  inc(i);
 end;
 if n1 < n then writeln(r) else writeln(l);
end.