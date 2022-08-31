program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

type
 TArray = array[0..100010] of integer;
 int53 = int64;
 edge = record
  x, y: integer;
 end;

procedure swap(var x, y: integer);
var
 z: integer;
begin
 z := x;
 x := y;
 y := z;
end;

function f(x: integer): integer;
begin
 result := x and (-x);
end;

var
 n, i, mdeg, fr, j, j1, j2, m, m1, x, y, x1, y1: integer;
 a: array[0..1000000] of edge;
 deg, clr, plc, cnt: TArray;
 lol: array[0..100000] of array of integer;

 first, data, next: array[0..200010] of integer;
 free: integer;

procedure add(x, y: integer);
begin
 next[free] := first[x];
 first[x] := free;
 data[free] := y;
 inc(free);
end;

procedure push(x, y, k: integer);
var
 i: integer;
begin
 i := y;
 while i <= cnt[x] do
 begin
  lol[x, i] := lol[x, i] + k;
  i := i + f(i);
 end;
end;

function sum(x, y: integer): integer;
var
 i, res: integer;
begin
 i := y;
 res := 0;
 while i > 0 do
 begin
  res := res + lol[x, i];
  i := i - f(i);
 end;
 result := res;
end;

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
 readln(n);
 free := 1;
 fr := 0;
 mdeg := 0;
 fillchar(deg, sizeof(deg), 0);
 fillchar(first, sizeof(first), 0);
 fillchar(next, sizeof(next), 0);
 fillchar(data, sizeof(data), 0);
 for i := 1 to n - 1 do
 begin
  readln(a[i].x, a[i].y);
  inc(deg[a[i].x]);
  inc(deg[a[i].y]);
  add(a[i].x, a[i].y);
  add(a[i].y, a[i].x);
  if deg[a[i].x] > mdeg then
  begin
   mdeg := deg[a[i].x];
   fr := a[i].x;
  end else
  if deg[a[i].y] > mdeg then
  begin
   mdeg := deg[a[i].y];
   fr := a[i].y;
  end;
 end;
 fillchar(clr, sizeof(clr), 0);
 fillchar(plc, sizeof(plc), 0);
 plc[fr] := 0;
 clr[fr] := 0;
 i := first[fr];
 m := 0;
 while i <> 0 do
 begin
  inc(m);
  m1 := 0;
  j := data[i];
  j1 := fr;
  while deg[j] > 1 do
  begin
   inc(m1);
   plc[j] := m1;
   j2 := j;
   clr[j] := m;
   if data[first[j]] <> j1 then j := data[first[j]] else j := data[next[first[j]]];
   j1 := j2;
  end;
  clr[j] := m;
  inc(m1);
  plc[j] := m1;
  cnt[m] := m1;
  setlength(lol[m], m1 + 1);
  i := next[i];
 end;
 readln(m);
 for i := 1 to m do
 begin
  read(x);
  if x = 1 then
  begin
   read(y);
   x1 := a[y].x;
   y1 := a[y].y;
   if plc[y1] < plc[x1] then swap(x1, y1);
   push(clr[y1], plc[y1], -1);
  end else
  if x = 2 then
  begin
   read(y);
   x1 := a[y].x;
   y1 := a[y].y;
   if plc[y1] < plc[x1] then swap(x1, y1);
   push(clr[y1], plc[y1], 1);
  end else
  begin
   read(x1, y1);
   if y1 = fr then swap(x1, y1);
   if x1 = fr then
   begin
    if y1 = fr then writeln(0) else
    if sum(clr[y1], plc[y1]) > 0 then writeln(-1) else
    writeln(plc[y1]);
   end else
   if clr[x1] <> clr[y1] then
   begin
    if (sum(clr[x1], plc[x1]) > 0) or (sum(clr[y1], plc[y1]) > 0) then writeln(-1) else
    writeln(plc[x1] + plc[y1]);
   end else
   begin
    if plc[x1] > plc[y1] then swap(x1, y1);
    if sum(clr[x1], plc[x1]) <> sum(clr[y1], plc[y1]) then writeln(-1) else
    writeln(plc[y1] - plc[x1]);
   end;
  end;
 end;
end.