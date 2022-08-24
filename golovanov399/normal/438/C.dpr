program qwe;

{$APPTYPE CONSOLE}
{$O+,R+,Q+}

uses
  SysUtils, Math;

const
  base = 1000000007;
  eps = 1e-4;

type
  point = record
   x, y: extended;
  end;
  line = record
   a, b, c: extended;
  end;

procedure swap(var x, y: extended);
var
 z: extended;
begin
 z := x;
 x := y;
 y := z;
end;

function urp(a, b, c: point): extended;
begin
 result := (a.y - b.y) * c.x + (b.x - a.x) * c.y + (a.x * b.y - a.y * b.x);
end;

function per(a, b, c, d: point): boolean;
begin
 result := (((urp(a, b, c) > 0) xor (urp(a, b, d) > 0))  or (urp(a, b, c) = 0) or (urp(a, b, d) = 0)) and (((urp(c, d, a) > 0) xor (urp(c, d, b) > 0)) or (urp(c, d, a) = 0) or (urp(c, d, b) = 0));
end;

function sgn(x: extended): integer;
begin
 if x > eps then result := 1 else
 if x < -eps then result := -1 else
 result := 0;
end;

function area(a, b, c: point): extended;
begin
    result := (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
end;

function intersect_1(a, b, c, d: extended): boolean;
begin
    if (a > b) then swap(a, b);
    if (c > d) then swap(c, d);
    result := (max(a,c) <= min(b,d));
end;

function intersect(a, b, c, d: point): boolean;
begin
    result := (intersect_1(a.x, b.x, c.x, d.x) and intersect_1(a.y, b.y, c.y, d.y) and (sgn(area(a,b,c) * area(a,b,d)) <= 0) and (sgn(area(c,d,a) * area(c,d,b)) <= 0));
end;

var
 n, i, j, l: integer;
 p: array[0..1000] of point;
 a: array[0..1000, 0..1000] of boolean;
 ss: extended;
 ar: array[0..1000, 0..1000] of integer;
 vsp, v: int64;
 bb: array[0..1000] of integer;
 pp: integer;
 xui: array[0..1000] of line;
 xxui: array[0..1000, 0..1000] of shortint;

function ok(s, f: integer): boolean;
var
 i: integer;
 t, w: extended;
 xep: line;
 k1, k2: shortint;
begin
 result := false;
 inc(pp);
 bb[s] := pp;
 bb[(s + n - 1) mod n] := pp;
 bb[f] := pp;
 bb[(f + n - 1) mod n] := pp;
 xep.a := p[s].y - p[f].y;
 xep.b := p[f].x - p[s].x;
 xep.c := -p[f].x * p[s].y + p[s].x * p[f].y;
 k2 := sgn(xep.a * p[0].x + xep.b * p[0].y + xep.c);
 for i := 0 to n - 1 do        //deg 1
 begin  //  -  ,   
  k1 := k2;
  k2 := sgn(xep.a * p[(i + 1) mod n].x + xep.b * p[(i + 1) mod n].y + xep.c);
  if ((xxui[i, s] = 0) and (xxui[i, f] = 0)) then
  begin
   if ((max(p[i].x, p[(i + 1) mod n].x) > min(p[s].x, p[f].x)) and (min(p[i].x, p[(i + 1) mod n].x) < max(p[s].x, p[f].x))) then exit;
   if ((max(p[i].y, p[(i + 1) mod n].y) > min(p[s].y, p[f].y)) and (min(p[i].y, p[(i + 1) mod n].y) < max(p[s].y, p[f].y))) then exit;
  end else
  if ((bb[i] <> pp) and (k1 * k2 <= 0) and (xxui[i, s] * xxui[i, f] <= 0)) then exit;
 end;
 i := s;
 t := 0;
 w := 0;
 while ((i + 1) mod n <> f) do        //deg 1
 begin
  i := (i + 1) mod n;
  t := t + ((p[i].x - p[s].x) * (p[(i + 1) mod n].y - p[s].y) - (p[i].y - p[s].y) * (p[(i + 1) mod n].x - p[s].x));
 end;
 i := f;
 while ((i + 1) mod n <> s) do        // deg 1
 begin
  i := (i + 1) mod n;
  w := w + ((p[i].x - p[f].x) * (p[(i + 1) mod n].y - p[f].y) - (p[i].y - p[f].y) * (p[(i + 1) mod n].x - p[f].x));
 end;
 if abs(abs(t) + abs(w) - ss) <= 1e-6 then
 result := true;
end;

begin
// reset(input, 'input.txt');
// rewrite(output, 'output.txt');
 readln(n);
 pp := 0;
 fillchar(bb, sizeof(bb), 0);
 for i := 0 to n - 1 do          //deg 1
 read(p[i].x, p[i].y);
 ss := 0;
 for i := 1 to n - 2 do          //deg 1
 ss := ss + ((p[i].x - p[0].x) * (p[i + 1].y - p[0].y) - (p[i].y - p[0].y) * (p[i + 1].x - p[0].x));
 ss := abs(ss);
 for i := 0 to n - 1 do
 begin
  xui[i].a := p[i].y - p[(i + 1) mod n].y;
  xui[i].b := p[(i + 1) mod n].x - p[i].x;
  xui[i].c := -p[(i + 1) mod n].x * p[i].y + p[i].x * p[(i + 1) mod n].y;
 end;
 for i := 0 to n - 1 do
 for j := 0 to n - 1 do
 xxui[i, j] := sgn(xui[i].a * p[j].x + xui[i].b * p[j].y + xui[i].c);
 for i := 0 to n - 1 do a[i, i] := false;
 for i := 0 to n - 2 do          //deg 1
 for j := i + 1 to n - 1 do      //deg 2
 begin
  if (((i + 1) mod n = j) or ((j + 1) mod n = i)) then a[i, j] := false else
  a[i, j] := ok(i, j);           //deg 3
  a[j, i] := a[i, j];
 end;    //  ,  ok  ,   ,  
 l := 0;
 for i := 0 to n - 2 do          //deg 1
 for j := i + 1 to n - 1 do      //deg 2
 if a[i, j] then inc(l);
// writeln(l);
// for i := 0 to n - 2 do          //deg 1
// for j := i + 1 to n - 1 do      //deg 2
// if a[i, j] then
// writeln(i + 1, ' ', j + 1);
 for i := 0 to n - 1 do          //deg 1
 ar[i, 0] := 0;
 for i := 0 to n - 1 do          //deg 1
 ar[i, 1] := 1;
 for l := 2 to n - 2 do          //deg 1
 begin
  for i := 0 to n - 1 do         //deg 2
  begin
   if a[i, (i + l) mod n] then
   begin
    v := ar[(i + 1) mod n, l - 1];
    for j := (l - 1) downto 1 do     //deg 3
    if a[i, (i + j) mod n] then
    begin
     vsp := int64(ar[i, j]);
     vsp := vsp * int64(ar[(i + j) mod n, l - j]);
     vsp := vsp mod base;
     v := (v + vsp) mod base;
    end;
    ar[i, l] := v mod base;
   end else
   ar[i, l] := 0;
  end;
 end;
 v := ar[1, n - 2];
 for i := (n - 2) downto 2 do     //deg 1
 if a[0, i] then
 begin
  vsp := int64(ar[0, i]);
  vsp := vsp * int64(ar[i, n - i - 1]);
  vsp := vsp mod base;
  v := (v + vsp) mod base;
 end;
 writeln(v);
end.