program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
//{$O+,Q-,R-,M+,I-}
{$O-,Q+,R+,M+,I+}


uses
  SysUtils;

const
  size = 1000;

var
  a, b, c, d : int64;
  len, i : integer;
  p, q, mg : array[-1 .. size] of int64;

procedure nod2(a, b : int64);
begin
  if b = 0 then
    exit;
  inc(len);
  mg[len] := a div b;
  nod2(b, a mod b);
end;

function nod(a, b : int64) : int64;
begin
  if b = 0 then
  begin
    nod := a;
    exit;
  end;
  nod := nod(b, a mod b);
end;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(a, b, c);
  if (b < 0) then
  begin
    a := -a;
    b := -b;
    //c := -c;
  end
  else
    c := -c;
  len := 0;
  d := nod(a, b);
  if c mod d <> 0 then
  begin
    writeln('-1');
    halt(0);
  end;
  a := a div d;
  b := b div d;
  c := c div d;
  nod2(a, b);
  p[0] := 1;
  p[-1] := 0;
  q[0] := 0;
  q[-1] := 1;
  for i := 1 to len - 1 do
  begin
    p[i] := -mg[i] * p[i - 1] + p[i - 2];
    q[i] := -mg[i]  * q[i - 1] + q[i - 2];
  end;
  writeln(q[len - 1] * c,' ',p[len - 1] * c);
end.