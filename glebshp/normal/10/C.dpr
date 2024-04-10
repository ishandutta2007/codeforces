program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  size = 1000 * 1000;

var
  dr : array[1 .. size] of integer;
  cnt : array[1 .. 9] of int64;
  n, i, dgrc, c, k, p : integer;
  ans : int64;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(n);
  for i := 1 to 9 do
    cnt[i] := 0;
  for i := 1 to n do
  begin
    c := i;
    dgrc := 0;
    while c > 0 do
    begin
      inc(dgrc, c mod 10);
      c := c div 10;
    end;
    if dgrc < 10 then
      dr[i] := dgrc
    else
      dr[i] := dr[dgrc];
    inc(cnt[dr[i]]);
  end;
  for i := 1 to 100 do
  begin
    c := i;
    dgrc := 0;
    while c > 0 do
    begin
      inc(dgrc, c mod 10);
      c := c div 10;
    end;
    if dgrc < 10 then
      dr[i] := dgrc
    else
      dr[i] := dr[dgrc];
  end;
  ans := 0;
  for i := 1 to 9 do
  begin
    for k := 1 to 9 do
      for p := 1 to 9 do
        if dr[k * p] = i then
          inc(ans, cnt[k] * cnt[p] * cnt[i]);
  end;
  for i := 1 to n do
    dec(ans, n div i);
  writeln(ans);
end.