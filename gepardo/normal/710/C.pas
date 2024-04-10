program magic;

{$coperators on}

var
  n: longint;
  a: array [1 .. 1000, 1 .. 1000] of longint;
  i, j, k, x, y: longint;
  sum, sum1, sum2: longint;

procedure bad;
begin
  writeln('Error :(');
  halt(256);
end;

begin
  readln(n);
  k := 0;
  for i := 1 to n do
    for j := 1 to n do
    begin
      inc(k);
      x := n div 2 + i - j + 1;
      y := -(n div 2) + i + j - 1;
      if x <= 0 then x += n;
      if x > n  then x -= n;
      if y <= 0 then y += n;
      if y > n  then y -= n;
      a[x, y] := k;
    end;
  // checking
  sum := 0;
  for i := 1 to n do sum += a[1, i];

  sum1 := 0; sum2 := 0;
  for i := 1 to n do
  begin
    sum1 += a[i, i];
    sum2 += a[n - i + 1, i];
  end;
  if (sum1 <> sum) or (sum2 <> sum) then bad;

  for i := 1 to n do
  begin
    sum1 := 0; sum2 := 0;
    for j := 1 to n do
    begin
      sum1 += a[i, j];
      sum2 += a[j, i];
    end;
    if (sum1 <> sum) or (sum2 <> sum) then bad;
  end;

  // output
  for i := 1 to n do
  begin
    for j := 1 to n do write(a[i, j], ' ');
    writeln;
  end;
end.