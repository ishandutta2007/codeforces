program hexagons;

const
  sinus = sqrt(3) / 2;
  cosinus = -0.5;

var
  a1, a2, a3, a4, a5, a6, s1, s2, s3, l1, l2, l3, s4, p, s: extended;
  r: longint;

begin
  readln(a1, a2, a3, a4, a5, a6);
  s1 := a1 * a2;
  s2 := a3 * a4;
  s3 := a5 * a6;
  l1 := sqrt(sqr(a1) + sqr(a2) - 2 * a1 * a2 * cosinus);
  l2 := sqrt(sqr(a3) + sqr(a4) - 2 * a3 * a4 * cosinus);
  l3 := sqrt(sqr(a5) + sqr(a6) - 2 * a5 * a6 * cosinus);
  p := (l1 + l2 + l3) / 2;
  s4 := sqrt(p) * sqrt(p - l1) * sqrt(p - l2) * sqrt(p - l3);
  s := s1 + s2 + s3 + (s4 / sinus * 2);
  r := round(s);
  writeln(r);
end.