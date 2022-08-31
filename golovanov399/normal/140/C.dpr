program qwe123;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
 TArray = array[1..100000] of integer;

procedure swap(var x, y: integer);
var
 z: integer;
begin
 z:=x;
 x:=y;
 y:=z;
end;

procedure QSort(var a, b: TArray; l, r: integer);
var
 i, j, x: integer;
begin
 if l>=r then exit;
 i:=l;
 j:=r;
 x:=a[l+random(r-l+1)];
 repeat
  while a[i]>x do inc(i);
  while a[j]<x do dec(j);
  if i<=j then
  begin
   swap(a[i], a[j]);
   swap(b[i], b[j]);
   inc(i);
   dec(j);
  end;
 until i>j;
 QSort(a, b, l, j);
 QSort(a, b, i, r);
end;

function hey(x, y, z: integer): string;
begin
 if x < y then swap(x, y);
 if y < z then swap(y, z);
 if x < y then swap(x, y);
 result := inttostr(x) + ' ' + inttostr(y) + ' ' + inttostr(z);
end;

var
 n, m, i, cnt: integer;
 a, b, c: TArray;
 str: array[1..100000] of string;

begin
// reset(input,'input.txt');
// rewrite(output,'output.txt');
 readln(n);
 randomize;
 for i:=1 to n do
 read(a[i]);
 QSort(a, b, 1, n);
 m:=1;
 fillchar(b, sizeof(b), 0);
 fillchar(c, sizeof(c), 0);
 b[1]:=1;
 c[1]:=a[1];
 cnt := 0;
 for i:=2 to n do
 begin
  if a[i]<>a[i-1] then inc(m);
  inc(b[m]);
  c[m]:=a[i];
 end;
 QSort(b, c, 1, m);
 while m >= 3 do
 begin
  inc(cnt);
  if (b[1] = b[2])and(b[2] = b[3]) then
  begin
   i := 3;
   while (i < m) and (b[i] = b[i + 1]) do
   inc(i);
   dec(b[i]);
   dec(b[i-1]);
   dec(b[i-2]);
   str[cnt]:=hey(c[i-2], c[i-1], c[i]);
  end else
  if (b[2] = b[3]) then
  begin
   i := 3;
   while (i < m) and (b[i] = b[i + 1]) do
   inc(i);
   dec(b[i]);
   dec(b[i-1]);
   dec(b[1]);
   str[cnt]:=hey(c[1], c[i-1], c[i]);
  end else
  begin
   i := 3;
   while (i < m) and (b[i] = b[i + 1]) do
   inc(i);
   dec(b[i]);
   dec(b[1]);
   dec(b[2]);
   str[cnt]:=hey(c[1], c[2], c[i]);
  end;
  while (m > 0)and(b[m] = 0) do dec(m);
 end;
 writeln(cnt);
 for i:=1 to cnt do
 writeln(str[i]);
end.