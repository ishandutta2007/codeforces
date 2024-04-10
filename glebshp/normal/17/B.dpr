program solution;

{$APPTYPE CONSOLE}
{$O+,Q-,R-,M+,I-}

uses
  SysUtils,
  Math;

const
  size = 1000;
  inf = 1000 * 1000 * 1000;

var
  way : array[1 .. size, 1 .. size] of int64;
  dist, q, col, from : array[1 ..size] of int64;
  used : array[1 .. size] of boolean;
  n, i, m, j, v, sp, dif, rc, cnt : integer;
  f, s, c : array[1 .. size * 10] of integer;
  sum : int64;

function getmin : integer;
var
  p, mn : integer;
begin
  p := 0;
  mn := inf + 1;
  for i := 1 to n do
    if not used[i] and (dist[i] < mn) then
    begin
      mn := dist[i];
      p := i;
    end;
  getmin := p;
end;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(n);
  for i := 1 to n do
    read(q[i]);
  read(m);
  for i := 1 to n do
    from[i] := inf;
  for i := 1 to m do
  begin
    read(f[i], s[i], c[i]);
    from[s[i]] := min(from[s[i]], c[i]);
  end;
  cnt := 0;
  sum := 0;
  for i := 1 to n do
    if from[i] = inf then
      inc(cnt)
    else
      inc(sum, from[i]);
  if cnt <> 1 then
    writeln('-1')
  else
    writeln(sum);


end.