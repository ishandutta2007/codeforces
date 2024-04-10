const
  Module = 1000000007;

var
  n: longint;
  c: array [0 .. 2000, 0 .. 2000] of int64;
  k: array [1 .. 2000] of longint;
  i, j, sum: longint;
  res: int64;

begin
  readln(n);
  for i := 1 to n do readln(k[i]);
  for i := 0 to 2000 do
    for j := 0 to 2000 do
      c[i, j] := 0;
  c[1, 1] := 1;
  for i := 2 to 2000 do
    for j := 1 to 2000 do
      c[i, j] := (c[i - 1, j] + c[i - 1, j - 1]) mod Module;

  {for i := 1 to 10 do
  begin
    for j := 1 to 10 do write(c[i, j], ' ');
    writeln;
  end;  }

  for i := 0 to 2000 do
    for j := 0 to 2000 do
      if c[i, j] = 0 then c[i, j] := 1;
  sum := 0; res := 1;
  for i := 1 to n do
  begin
    res := (res * c[sum + k[i], k[i]]) mod Module;
    //writeln(c[sum + k[i], k[i]], ' ', sum + k[i] - 1, ' ', k[i], ' ', i, ' ', res);
    inc(sum, k[i]);
  end;
  writeln(res);
end.