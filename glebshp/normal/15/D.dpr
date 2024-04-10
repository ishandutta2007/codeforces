program solution;

{$APPTYPE CONSOLE}
//{$O-,Q+,R+,M+,I+}
{$O+,Q-,R-,M+,I-}

uses
  SysUtils,
  Math;

const
  inf = 1000 * 1000 * 1000 + 100;
  size = 1000;

type
  stack = record
    body : array[1 .. size] of integer;
    mn : array[1 .. size] of integer;
    len : integer;
  end;

  queue = record
    f, s : stack;
  end;

var
  rightbest, field : array[1 .. size, 1 .. size] of integer;
  sum, best : array [0 .. size, 0 .. size] of int64;
  n, m, a, b, i, j, len, ans, p, r : integer;
  q : queue;
  x, y, rx, ry : array[1 .. size * size] of integer;
  res, ra : array[1 .. size * size] of int64;
  used : array[1 .. size, 1 .. size] of boolean;

procedure push(var s : stack; c : integer);
begin
  if s.len = 0 then
  begin
    s.len := 1;
    s.body[1] := c;
    s.mn[1] := c;
  end
  else
  begin
    inc(s.len);
    s.body[s.len] := c;
    s.mn[s.len] := min(s.mn[s.len - 1], c);
  end;
end;

procedure pop(var s : stack);
begin
  dec(s.len);
end;

procedure push_queue(var q : queue; c : integer);
begin
  push(q.f, c);
end;

procedure pop_queue(var q : queue);
begin
  if q.s.len > 0 then
    dec(q.s.len)
  else
  begin
  while q.f.len > 0 do
  begin
    push(q.s, q.f.body[q.f.len]);
    dec(q.f.len);
  end;
      dec(q.s.len);

  end;
end;

function ms(var s : stack) : integer;
begin
  if s.len = 0 then
    ms := inf
  else
    ms := s.mn[s.len];
end;

function getmin(var q : queue) : integer;
begin
  getmin := min(ms(q.f), ms(q.s));
end;

procedure qsort(i, j : integer);
var
  l, r, kx, ky, spint : integer;
  kb, sp : int64;
begin
  if i >= j then
    exit;
  l := i;
  r := j;
  spint := i + random(j - i + 1);
  kb := res[spint];
  kx := x[spint];
  ky := y[spint];
  while l <= r do
  begin
    while (res[l] < kb) or ((res[l] = kb) and (x[l] < kx)) or ((res[l] = kb) and (x[l] = kx) and (y[l] < ky)) do
      inc(l);
    while (res[r] > kb) or ((res[r] = kb) and (x[r] > kx)) or ((res[r] = kb) and (x[r] = kx) and (y[r] > ky)) do
      dec(r);
    if l <= r then
    begin
      sp := res[l];
      res[l] := res[r];
      res[r] := sp;
      spint := x[l];
      x[l] := x[r];
      x[r] := spint;
      spint := y[l];
      y[l] := y[r];
      y[r] := spint;
      inc(l);
      dec(r);
    end;
  end;
  qsort(i, r);
  qsort(l, j);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n, m, a, b);
  for i := 1 to n do
    for j := 1 to m do
      read(field[i, j]);
  for i := 1 to n do
  begin
    q.s.len := 0;
    q.f.len := 0;
    for j := 1 to b do
      push_queue(q, field[i, j]);
    rightbest[i, 1] := getmin(q);
    for j := b + 1 to m do
    begin
      push_queue(q, field[i, j]);
      pop_queue(q);
      rightbest[i, j - b + 1] := getmin(q);
    end;
  end;
  for j := 1 to m do
  begin
    q.s.len := 0;
    q.f.len := 0;
    for i := 1 to a do
      push_queue(q, rightbest[i, j]);
    best[1, j] := getmin(q);
    for i := a + 1 to n do
    begin
      push_queue(q, rightbest[i, j]);
      pop_queue(q);
      best[i - a + 1, j] := getmin(q);
    end;
  end;
  for i := 1 to n do
    for j := 1 to m do
      sum[i, j] := sum[i - 1, j] + sum[i, j - 1] - sum[i - 1, j - 1] + field[i, j];
  for i := 1 to (n - a + 1) do
    for j := 1 to (m - b + 1) do
      best[i, j] := (sum[i + a - 1, j + b - 1] - sum[i + a - 1, j - 1] - sum[i - 1, j + b - 1] + sum[i - 1, j - 1]) - best[i, j] * a * b;
  len := 0;
  for i := 1 to (n - a + 1) do
    for j := 1 to (m - b + 1) do
    begin
      inc(len);
      res[len] := best[i, j];
      x[len] := i;
      y[len] := j;
    end;
  qsort(1, len);
  ans := 0;
  for i := 1 to len do
    if not used[x[i], y[i]] then
    begin
      inc(ans);
      ra[ans] := res[i];
      rx[ans] := x[i];
      ry[ans] := y[i];
      for p := max(1, x[i] - a + 1) to min(n, x[i] + a - 1) do
        for r := max(1, y[i] - b + 1) to min(m, y[i] + b - 1) do
          used[p, r] := true;
    end;
  writeln(ans);
  for i := 1 to ans do
    writeln(rx[i],' ',ry[i],' ',ra[i]);
end.