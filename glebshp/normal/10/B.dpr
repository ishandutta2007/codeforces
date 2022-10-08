program solution;

{$APPTYPE CONSOLE}
{$O+,R-,Q-,M+,I-}

uses
  SysUtils;

const
  size = 100;
  inf = 1000 * 1000 * 1000;

var
  ans : array[1 .. size, 1 .. size, 1 .. size] of integer;
  used : array[1 .. size, 1 .. size] of boolean;
  free : array[1 .. size, 1 .. size] of integer;
  i, j, p, n, k, m, best, bx, by, md, q, last : integer;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(n, k);
  md := k div 2 + 1;
  for i := 1 to k do
    for j := 1 to k do
      for p := 1 to k do
        ans[i, j, p] := inf;
  for i := 1 to k do
    for j := 1 to k do
    begin
      ans[i, j, 1] := abs(i - md) + abs(j - md);
      for p := 2 to k - j + 1 do
        ans[i, j, p] := ans[i, j, p - 1] + abs(i - md) + abs(j + p - 1 - md);
    end;
  for i := 1 to k do
    for j := 1 to k do
      free[i, j] := k - j + 1;
  for i := 1 to n do
  begin
    read(m);
    best := inf;
    bx := 0;
    by := 0;
    for p := 1 to k do
      for q := 1 to k do
        if (free[p, q] >= m) and (ans[p, q, m] < best) then
        begin
          best := ans[p, q, m];
          bx := p;
          by := q;
        end;
    if best < inf then
    begin
      writeln(bx,' ',by,' ',by + m - 1);
      for j := 1 to m do
        used[bx, by + j - 1] := true;
      last := k + 1;
      for j := k downto 1 do
      begin
        if used[bx, j] then
          last := j;
        free[bx, j] := last - j;
      end;
    end
    else
      writeln('-1');
  end;
end.