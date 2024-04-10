program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  size = 19;

var
  n, m, i, j, k, p, s, f : integer;
  ans : array[1 .. 1 shl size, 1 .. size] of int64;
  way : array[1 .. size, 1 .. size] of boolean;
  step : array[1 .. size] of integer;
  res : int64;

begin
  //reset(input,'input.txt');
 // rewrite(output,'output.txt');
  read(n, m);
  for i := 1 to m do
  begin
    read(s, f);
    way[s, f] := true;
    way[f, s] := true;
  end;
  step[1] := 1;
  for i := 2 to n do
    step[i] := step[i - 1] * 2;
  for i := n downto 3 do
  begin
    for j := 1 to step[i] - 1 do
      for k := 1 to i - 1 do
        ans[j, k] := 0;
    for j := 1 to i - 1 do
      if way[i, j] then
        ans[step[j], j] := 1;
    for j := 1 to step[i] - 1 do
      for k := 1 to i - 1 do
        if (step[k] <> j) and (((j shr (k - 1)) and 1) = 1) then
        begin
          ans[j, k] := 0;
          for p := 1 to i - 1 do
            if (p <> k) and ((j shr (p - 1)) and 1 = 1) and way[k, p] then
              inc(ans[j, k], ans[j - step[k], p]);
          if way[i, k] then
            inc(res, ans[j, k]);
        end;
  end;
  writeln(res div 2);
end.