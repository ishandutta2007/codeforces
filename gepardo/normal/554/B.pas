var
  n, max: longint;
  s: array [1 .. 300] of string;
  c: array [1 .. 300] of longint;
  wc, i, j: longint;

begin
  readln(n); wc := 0;
  for i := 1 to n do readln(s[i]);
  for i := 1 to n do
  begin
    c[i] := 0;
    for j := 1 to n do
      if s[i] = s[j] then inc(c[i]);
  end;
  max := c[1];
  for i := 2 to n do
    if c[i] > max then max := c[i];
  writeln(max);
end.