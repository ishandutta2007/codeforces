program solution;

{$H+}
{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  integer = longint;

const
  size = 1000;

var
  name, pl : array[1 .. size] of string;
  pts, res : array[1 .. size] of integer;
  u, br, nbr, p, i, j, n, cnt, len : integer;
  used : array[1 .. size] of boolean;
  a : char;
  flag : boolean;
  brh : string;

begin
//  reset(input,'input.txt');
//  rewrite(output,'output.txt');
  readln(n);
  for i := 1 to n do
  begin
    name[i] := '';
    while true do
    begin
      read(a);
      if a = ' ' then
        break
      else
        name[i] := name[i] + a;
    end;
    readln(pts[i]);
  end;
  len := 0;
  for i := 1 to n do
  begin
    p := 0;
    for j := 1 to len do
      if pl[j] = name[i] then
        p := j;
    if p = 0 then
    begin
      inc(len);
      pl[len] := name[i];
      res[len] := pts[i];
    end
    else
      inc(res[p], pts[i]);
  end;
  flag := false;
  br := -1000 * 1000;
  for i := 1 to len do
    if (res[i] = br) then
      flag := true
    else
      if (res[i] > br) then
      begin
        br := res[i];
        brh := pl[i];
        flag := false;
      end;
  if not flag then
    writeln(brh)
  else
  begin
    for i := 1 to n do
      if res[i] = br then
        used[i] := true;
    nbr := 1000 * 1000;
    p := 0;
    for i := 1 to len do
    if used[i] then
    begin
      cnt := 0;
      u := 1000 * 1000;
      for j := 1 to n do
      begin
        if pl[i] = name[j] then
          inc(cnt, pts[j]);
        if cnt >= br then
        begin
          u := j;
          break;
        end;
      end;
      if u < nbr then
      begin
        nbr := u;
        p := i;
      end;
    end;
    writeln(pl[p]);
  end;


end.