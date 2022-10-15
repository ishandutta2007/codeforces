uses math;

var n, r: extended;

begin
  readLn(n, r);
  writeLn(((n * r * r) / (1 / tan(pi / 2 / n) + 1 / tan(pi / n))) : 0 : 9);
end.