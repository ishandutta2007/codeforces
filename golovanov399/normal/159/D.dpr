program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

type
 tlong = record
  n: integer;
  a: array[1..1000] of shortint;
 end;

function inttolong(x: integer): tlong;
var
 y: tlong;
begin
 fillchar(y, sizeof(y), 0);
 while x > 0 do
 begin
  inc(y.n);
  y.a[y.n] := x mod 10;
  x := x div 10;
 end;
 if y.n = 0 then y.n := 1;
 result := y;
end;

function sloj(x, y: tlong): tlong;
var
 i, k: integer;
 z: tlong;
begin
 fillchar(z, sizeof(z), 0);
 k := 0;
 i := 1;
 while (i <= x.n) or (i <= y.n) or (k > 0) do
 begin
  z.a[i] := (x.a[i] + y.a[i] + k) mod 10;
  k := (x.a[i] + y.a[i] + k) div 10;
  inc(i);
 end;
 if i <= 1 then z.n := 1 else z.n := i - 1;
 result := z;
end;

function umn(x: tlong; m: integer): tlong;
var
 i, k: integer;
 z: tlong;
begin
 fillchar(z, sizeof(z), 0);
 k := 0;
 i := 1;
 while (i <= x.n) or (k > 0) do
 begin
  z.a[i] := (x.a[i] * m + k) mod 10;
  k := (x.a[i] * m + k) div 10;
  inc(i);
 end;
 if i <= 1 then z.n := 1 else z.n := i - 1;
 result := z;
end;

procedure printdlin(x: tlong);
var
 i: integer;
begin
 if x.n = 0 then write(0) else
 begin
  for i := x.n downto 1 do
  write(x.a[i]);
 end;
end;

var
 s: string;
 n, i, j, len, vsp: integer;
 l: array[0..5000] of integer;
 ans: tlong;
 c, d: array[1..2000] of integer;

begin
 fillchar(c, sizeof(c), 0);
 fillchar(d, sizeof(d), 0);
 readln(s);
 n := 0;
 j := 0;
 len := length(s);
 i := len;
 s := s + '#';
 while i > 0 do
 begin
  s := s + s[i];
  dec(i);
 end;
 while s <> '#' do
 begin
  l[0] := 0;
  l[1] := 0;
  for i := 2 to length(s) do
  begin
   l[i] := l[i - 1];
   while (l[i] > 0) and (s[i] <> s[l[i] + 1]) do l[i] := l[l[i]];
   if s[i] = s[l[i] + 1] then inc(l[i]);
  end;
  i := length(s);
  while l[i] > 0 do
  begin
   inc(n);
   inc(c[j + 1]);
   inc(d[j + l[i]]);
   i := l[i];
  end;
  delete(s, 1, 1);
  delete(s, length(s), 1);
  inc(j);
 end;
 ans := inttolong(0);
 vsp := n;
 for i := 1 to len - 1 do
 begin
  vsp := vsp - c[i]; {
  vsp1 := vsp * d[i];
  ans := ans + vsp1; }
  ans := sloj(ans, umn(inttolong(vsp), d[i]));
 end;
// writeln(ans);
 printdlin(ans);
end.