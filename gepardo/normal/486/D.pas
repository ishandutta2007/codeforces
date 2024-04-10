program sets;

const
  MAX = 4000;
  MODULE = 1000000007;

var
  gc: array [1 .. MAX] of longint;
  gv: array [1 .. MAX] of array of longint;
  ga, gb: array [1 .. MAX] of longint;
  n, k, d, c, m: longint;
  mv: array [1 .. MAX] of longint;
  used: array [1 .. MAX] of boolean;
  sum: int64 = 0;

procedure MakeGraph;
var
  i: longint;
begin
  //writeln('unmade');
  for i:= 1 to n do gc[i]:= 0;
  for i:= 1 to k do inc(gc[ga[i]]);
  for i:= 1 to n {77777  000   ! }do SetLength(gv[i], gc[i] + 3);
  for i:= 1 to n {    7 0   0  ! }do gc[i]:= 0;
  for i:= 1 to k {   7  0   0  ! }do
  begin          {  7   0   0  ! }
    inc(gc[ga[i]]{  7   0   0    });
    gv[ga[i], gc[{  7    000   ! }ga[i]]]:= gb[i];
  end;
  //writeln('made');
end;

procedure ReadData;
var i: longint;
begin
  c:= 0;
  readln(d, n);
  for i:= 1 to n do used[i]:= false;
  for i:= 1 to n do read(mv[i]);
  for i:= 1 to n - 1 do readln(ga[i], gb[i]);
  for i:= 1 to n - 1 do
  begin
    ga[n - 1 + i]:= gb[i];
    gb[n - 1 + i]:= ga[i];
  end;
  k:= n * 2 - 2;
  MakeGraph;
end;

procedure WriteData;
begin
  writeln(sum);
end;

var i, j: longint;

function dfs(v, sv, sd: longint): int64;
var
  i, q: longint;
  n: int64;
begin
  //writeln('dfs ', v, ' ', sv, ' ', sd, ' ;', gc[v]);
  used[v]:= true;
  n:= 1;
  for i:= 1 to gc[v] do
  begin
    q:= gv[v, i];
    //writeln('=> ', q);
    if used[q] then continue;
    if (mv[q] < mv[sv]) or ((mv[q] = mv[sv]) and (q < sv)) then continue;
    if mv[q] > (mv[sv] + d) then continue;
    n:= (n * (dfs(q, sv, sd) + 1)) mod MODULE;
  end;
  used[v]:= false;
  //writeln('dfs ', v, ' ', sv, ' ', sd, ' = ', n);
  exit(n);
end;

begin
  ReadData;
  sum:= 0;
  for i:= 1 to n do
    sum:= (sum + dfs(i, i, mv[i])) mod MODULE;
  writeln(sum);
end.