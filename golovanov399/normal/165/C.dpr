program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

type
 TArray = array[0..1000010] of integer;
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
 a: TArray;
 m, i, k: integer;
 vsp, ans: int64;
 s: string;
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
 readln(k);
 readln(s);
 m := 1;
 fillchar(a, sizeof(a), 0);
 a[1] := 1;
 for i := 1 to length(s) do
 begin
  if s[i] = '0' then inc(a[m]) else
  begin
   inc(m);
   a[m] := 1;
  end;
 end;
 ans := 0;
 if k = 0 then
 begin
  for i := 1 to m do
  begin
   vsp := a[i] - 1;
   vsp := vsp * a[i];
   vsp := vsp div 2;
   ans := ans + vsp;
  end;
 end else
 begin
  for i := 1 to m - k do
  begin
   vsp := a[i];
   vsp := vsp * a[i + k];
   ans := ans + vsp;
  end;
 end;
 writeln(ans);
end.