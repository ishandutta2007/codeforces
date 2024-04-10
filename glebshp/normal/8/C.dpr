program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
//{$O-,Q+,R+,M+,I+}
{$O+,Q-,R-,M+,I-}

uses
  SysUtils;

const
  size = 1 shl 25;
  lim = 30;
  inf = 1000 * 1000 * 1000;

var
  ans, from1, from2 : array[0 .. size] of integer;
  ow, step, x, y, num : array[0 .. lim] of integer;
  way : array[0 .. lim, 0 .. lim] of integer;
  pr, xc, yc, n, i, j, k, len : integer;

procedure razvorot(p : integer);
var
  i : integer;
begin
  len := 0;
  for i := 1 to n do
  begin
    if p mod 2 = 1 then
    begin
      inc(len);
      num[len] := i;
    end;
    p := p div 2;
  end;
end;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(xc, yc);
  read(n);
  for i := 1 to n do
    read(x[i], y[i]);
  for i := 1 to n do
    for j := 1 to n do
      way[i, j] := sqr(x[i] - xc) + sqr(y[i] - yc) + sqr(x[j] - xc) + sqr(y[j] - yc) + sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
  for i := 1 to n do
    ow[i] := (sqr(x[i] - xc) + sqr(y[i] - yc)) * 2;
  step[0] := 0;
  step[1] := 1;
  for i := 2 to n do
    step[i] := step[i - 1] * 2;
  pr := (1 shl n) - 1;
  ans[0] := 0;
  from1[0] := 0;
  from2[0] := 0;
  for i := 1 to pr do
  begin
    ans[i] := inf;
    razvorot(i);
    //if (len mod 2 = 0) then
    //begin
    {if len > 1 then
      for j := 1 to len - 1 do
        for k := j + 1 to len do
          if ans[i] > ans[i - step[num[j]] - step[num[k]]] + way[num[j], num[k]] then
          begin
            ans[i] := ans[i - step[num[j]] - step[num[k]]] + way[num[j], num[k]];
            from1[i] := num[j];
            from2[i] := num[k];
          end;
    }
    for j := 1 to len do
      if ans[i] > ans[i - step[num[j]]] + ow[num[j]] then
      begin
        ans[i] := ans[i - step[num[j]]] + ow[num[j]];
        from1[i] := num[j];
        from2[i] := 0;
      end;
    for j := 2 to len do
      if ans[i] > ans[i - step[num[1]] - step[num[j]]] + way[num[1], num[j]] then
      begin
        ans[i] := ans[i - step[num[1]] - step[num[j]]] + way[num[1], num[j]];
        from1[i] := num[1];
        from2[i] := num[j];
      end;
    //end;
  end;
  {if n mod 2 = 1 then
  begin
    ans[pr] := inf;
    for i := 1 to n do
      if ans[pr] > ans[pr - step[i]] + ow[i] then
      begin
        ans[pr] := ans[pr - step[i]] + ow[i];
        from1[pr] := i;
        from2[pr] := 0;
      end;
  end;
  }
  writeln(ans[pr]);
  write('0');
  while pr <> 0 do
  begin
    write(' ',from1[pr],' ');
    if from2[pr] <> 0 then
      write(from2[pr],' ');
    write('0');
    pr := pr - step[from1[pr]] - step[from2[pr]];
  end;
end.