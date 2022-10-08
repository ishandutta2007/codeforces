program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$O-,Q+,R+,M+,I+}
//{$O+,Q-,R-,M+,I+}

uses
  SysUtils,
  Math;

const
  e = 1e-10;
  size = 1000;
  zn = 10;
  eps = 1e-14;

type
  double = extended;

  point = record
    x, y : double;
  end;

  line = record
    a, b, c : double;
  end;

  circle = record
    c : point;
    r : double;
  end;

var
  cir : array[0 .. size] of circle;
  pts : array[0 .. size] of point;
  i, j : integer;
  h, s, c : point;
  l, r, k, t1, t2 : double;

function dist(p1, p2 : point) : double;
begin
  dist := sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
end;

function line_dist(l : line; p : point) : double;
begin
  line_dist := l.a * p.x + l.b * p.y + l.c;
end;

procedure normalize(var l : line);
var
  k : double;
begin
  k := sqrt(l.a * l.a + l.b * l.b);
  l.a := l.a / k;
  l.b := l.b / k;
  l.c := l.c / k;
end;

function cross_circle_line(c : circle; l : line; var p1, p2 : point) : boolean;
var
  d : double;
begin
  d := line_dist(l, c.c);
  if d > c.r + e then
  begin
    cross_circle_line := false;
    exit;
  end;
  p1.x := c.c.x - l.a * d;
  p1.y := c.c.y - l.b * d;
  d := sqrt(abs(sqr(c.r) - d * d));
  p2.x := p1.x - l.b * d;
  p2.y := p1.y + l.a * d;
  p1.x := p1.x + l.b * d;
  p1.y := p1.y - l.a * d;
  cross_circle_line := true;
end;

function cross_circle_circle(c1, c2 : circle; var p1, p2 : point) : boolean;
var
  l : line;
  hc : circle;
begin
  if c1.r < c2.r then
  begin
    hc := c1;
    c1 := c2;
    c2 := hc;
  end;
  if dist(c1.c, c2.c) + c2.r < c1.r + e then
  begin
    p1 := c2.c;
    p2 := c2.c;
    cross_circle_circle := true;
    exit;
  end;
  l.a := - 2 * (c1.c.x - c2.c.x);
  l.b := - 2 * (c1.c.y - c2.c.y);
  l.c := sqr(c1.c.x) + sqr(c1.c.y) - sqr(c2.c.x) - sqr(c2.c.y) - sqr(c1.r) + sqr(c2.r);
  normalize(l);
  cross_circle_circle := cross_circle_line(c1, l, p1, p2);
end;

function inside(c : circle; p : point) : boolean;
begin
  inside := dist(c.c, p) - c.r < e;
end;

function check(k : double) : boolean;
var
  p1, p2 : point;
  i, j, len : integer;
begin
  cir[0].r := k;
  cir[1].r := t2 - k;
  cir[2].r := t1 - k;
  len := 0;
  for i := 0 to 1 do
    for j := i + 1 to 2 do
      if cross_circle_circle(cir[i], cir[j], p1, p2) then
      begin
        pts[len + 1] := p1;
        pts[len + 2] := p2;
        inc(len, 2);
      end;
  for i := 1 to len do
    if inside(cir[0], pts[i]) and inside(cir[1], pts[i]) and inside(cir[2], pts[i]) then
    begin
      check := true;
      exit;
    end;
  check := false;
end;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(t1, t2);
  read(c.x, c.y);
  read(h.x, h.y);
  read(s.x, s.y);
  cir[0].c.x := c.x;
  cir[0].c.y := c.y;
  cir[1].c.x := h.x;
  cir[1].c.y := h.y;
  cir[2].c.x := s.x;
  cir[2].c.y := s.y;
  t1 := t1 + dist(c, s) + dist(s, h);
  t2 := t2 + dist(c, h);
  if t2 > dist(c, s) + dist(s, h) - e then
    writeln(min(t1, t2) : 0 : zn)
  else
  begin
    t1 := t1 - dist(s, h);
    l := 0;
    r := min(t1, t2);
    while r - l > eps do
    begin
      k := (l + r) / 2;
      if check(k) then
        l := k
      else
        r := k;
    end;
    writeln(l : 0 : zn);
  end;
end.