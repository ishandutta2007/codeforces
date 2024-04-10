program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

var
 data, next, head: array[1..200020] of integer;
 free, n, m, i, k, x, y, cnt: integer;
 b: array[1..100020] of boolean;
 clr: array[1..100020] of integer;
 vsp: int64;

function sqrr(a, b: integer): int64;
var
 res, dega: int64;
begin
 res := 1;
 dega := a;
 while b > 0 do
 begin
  if odd(b) then
  begin
   res := res * dega;
   res := res mod k;
  end;
  dega := dega * dega;
  dega := dega mod k;
  b := b div 2;
 end;
 result := res mod k;
end;

procedure add(x, y: integer);
begin
 next[free] := head[x];
 head[x] := free;
 data[free] := y;
 inc(free);
end;

procedure dfs(x: integer);
begin
 b[x] := true;
 inc(clr[cnt]);
 x := head[x];
 while x > 0 do
 begin
  if not b[data[x]] then dfs(data[x]);
  x := next[x];
 end;
end;

begin
 free := 1;
 readln(n, m, k);
 for i := 1 to m do
 begin
  readln(x, y);
  add(x, y);
  add(y, x);
 end;
 fillchar(b, sizeof(b), 0);
 fillchar(clr, sizeof(clr), 0);
 cnt := 0;
 i := 1;
 while i <= n do
 begin
  while (i <= n) and (b[i]) do inc(i);
  if i <= n then
  begin
   inc(cnt);
   dfs(i);
  end;
 end;
 if cnt = 1 then
 begin
  writeln(1 mod k);
  halt(0);
 end else
 if cnt = 2 then
 begin
  vsp := clr[1] mod k;
  vsp := vsp * clr[2];
  vsp := vsp mod k;
  writeln(vsp);
  halt(0);
 end else
 begin
  vsp := 1 mod k;
  for i := 1 to cnt do
  begin
   vsp := vsp * clr[i];
   vsp := vsp mod k;
  end;
  vsp := vsp * sqrr(n, cnt - 2);
  vsp := vsp mod k;
  writeln(vsp);
 end;
end.