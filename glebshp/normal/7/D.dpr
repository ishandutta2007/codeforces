program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  size = 11 * 1000 * 1000;

var
  body : array[1 .. size] of char;
  z, ans : array[0 .. size] of integer;
  len, i, j,  b : integer;
  a : char;
  sum : int64;

begin
  //{$IFDEF MSWINDOWS}
   // reset(input,'input.txt');
   // rewrite(output,'output.txt');
  //{$ENDIF}
  len := 0;
  while true do
  begin
    read(a);
    if a < #32 then
      break;
    inc(len);
    body[len] := a;
  end;
  inc(len);
  body[len] := '#';
  for i := len - 1 downto 1 do
  begin
    inc(len);
    body[len] := body[i];
  end;
  inc(len);
  body[len] := '%';
  z[1] := 0;
  b := 1;
  for i := 2 to len do
  begin
    if b + z[b] - 1 < i then
      z[i] := 0
    else
      z[i] := min(z[b] + b - 1 - i, z[i - b + 1]);
    while body[i + z[i]] = body[z[i] + 1] do
      inc(z[i]);
    if i + z[i] > b + z[b] then
      b := i;
  end;
  ans[0] := 0;
  for i := 1 to len div 2 - 1 do
  begin
    if z[len - i] >= i then
      ans[i] := ans[i div 2] + 1
    else
      ans[i] := 0;
    inc(sum, ans[i]);
  end;
  writeln(sum);
end.