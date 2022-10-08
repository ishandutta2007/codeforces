program solution;

{$APPTYPE CONSOLE}
//{$O-,Q+,R+,M+,I+}
{$O+,Q-,R-,M+,I-}
uses
  SysUtils, Math;

type
  integer = longint;

const
  size = 1000;
  inf = 1000 * 1000 * 1000;

var
  fv, dv, mat, mdvdv, mdvfv, mfvdv, mfvfv : array[0 .. size, 0 .. size] of integer;
  fromdv, fromfv : array[0 .. size, 0 .. size] of boolean;
  i, j, n, c, x, y, l, best : integer;
  st : array[0 .. size * size] of char;
  flag : boolean;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(n);
  for i := 1 to n do
    for j := 1 to n do
      read(mat[i, j]);
  for i := 1 to n do
    for j := 1 to n do
    begin
      c := mat[i, j];
      while (c > 0) and (c mod 5 = 0) do
      begin
        inc(fv[i, j]);
        c := c div 5;
      end;
      while (c > 0) and (c mod 2 = 0) do
      begin
        inc(dv[i, j]);
        c := c div 2;
      end;
    end;
  for i := 1 to n do
  begin
    mdvdv[i, 0] := inf;
    mdvfv[i, 0] := inf;
    mfvdv[i, 0] := inf;
    mfvfv[i, 0] := inf;
    mdvdv[i, n + 1] := inf;
    mdvfv[i, n + 1] := inf;
    mfvdv[i, n + 1] := inf;
    mfvfv[i, n + 1] := inf;
    mdvdv[0, i] := inf;
    mdvfv[0, i] := inf;
    mfvdv[0, i] := inf;
    mfvfv[0, i] := inf;
    mdvdv[n + 1, i] := inf;
    mdvfv[n + 1, i] := inf;
    mfvdv[n + 1, i] := inf;
    mfvfv[n + 1, i] := inf;
  end;
  mdvdv[0, 1] := 0;
  mdvfv[0, 1] := 0;
  mfvdv[0, 1] := 0;
  mfvfv[0, 1] := 0;
  mdvdv[1, 0] := 0;
  mdvfv[1, 0] := 0;
  mfvdv[1, 0] := 0;
  mfvfv[1, 0] := 0;
  for i := 1 to n do
    for j := 1 to n do
    begin
      if (mdvdv[i - 1, j] < mdvdv[i, j - 1]) or ((mdvdv[i - 1, j] = mdvdv[i, j - 1]) and (mdvfv[i - 1, j] < mdvfv[i, j - 1])) then
      begin
        mdvdv[i, j] := mdvdv[i - 1, j] + dv[i, j];
        mdvfv[i, j] := mdvfv[i - 1, j] + fv[i, j];
        fromdv[i, j] := true;
      end
      else
      begin
        mdvdv[i, j] := mdvdv[i, j - 1] + dv[i, j];
        mdvfv[i, j] := mdvfv[i, j - 1] + fv[i, j];
        fromdv[i, j] := false;
      end;
      if (mfvfv[i - 1, j] < mfvfv[i, j - 1]) or ((mfvfv[i - 1, j] = mfvfv[i, j - 1]) and (mfvdv[i - 1, j] < mfvdv[i, j - 1])) then
      begin
        mfvdv[i, j] := mfvdv[i - 1, j] + dv[i, j];
        mfvfv[i, j] := mfvfv[i - 1, j] + fv[i, j];
        fromfv[i, j] := true;
      end
      else
      begin
        mfvdv[i, j] := mfvdv[i, j - 1] + dv[i, j];
        mfvfv[i, j] := mfvfv[i, j - 1] + fv[i, j];
        fromfv[i, j] := false;
      end;
    end;
  best := min(min(mdvdv[n, n], mdvfv[n, n]), min(mfvdv[n, n], mfvfv[n, n]));
  flag := false;
  for i := 1 to n do
    for j := 1 to n do
      if mat[i, j] = 0 then
      begin
        flag := true;
        x := i;
        y := j;
      end;
  if flag and (best >= 1) then
  begin
    writeln('1');
    for i := 1 to x - 1 do
      write('D');
    for i := 1 to y - 1 do
      write('R');
    for i := x to n - 1 do
      write('D');
    for j := y to n - 1 do
      write('R');
  end
  else
  begin
    writeln(best);
    if min(mdvdv[n, n], mdvfv[n, n]) < min(mfvdv[n, n], mfvfv[n, n]) then
    begin
      x := n;
      y := n;
      l := 0;
      while (x <> 1) and (y <> 1) do
      begin
        inc(l);
        if fromdv[x, y] then
        begin
          st[l] := 'D';
          dec(x);
        end
        else
        begin
          st[l] := 'R';
          dec(y);
        end;
      end;
      for i := 2to x do
      begin
        inc(l);
        st[l] := 'D';
      end;
      for i := 2 to y do
      begin
        inc(l);
        st[l] := 'R';
      end;
      for i := l downto 1 do
        write(st[i]);
    end
    else
    begin
      x := n;
      y := n;
      l := 0;
      while (x <> 1) and (y <> 1) do
      begin
        inc(l);
        if fromfv[x, y] then
        begin
          st[l] := 'D';
          dec(x);
        end
        else
        begin
          st[l] := 'R';
          dec(y);
        end;
      end;
      for i := 2 to x do
      begin
        inc(l);
        st[l] := 'D';
      end;
      for i := 2 to y do
      begin
        inc(l);
        st[l] := 'R';
      end;
      for i := l downto 1 do
        write(st[i]);
    end;
  end;
end.