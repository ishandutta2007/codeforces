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
  used, have : array[1 .. size] of boolean;
  st, sb, bl : array[1 .. size] of integer;
  t, m, i, j, b, k, p, sz, len, n, nm : integer;
  a, c : char;
  line : string;
  flag : boolean;

function check(v, c : integer) : boolean;
var
  i : integer;
begin
  if v + c - 1 > n then
  begin
    check := false;
    exit;
  end;
  for i := 1 to c do
    if used[v + i - 1] then
    begin
      check := false;
      exit;
    end;
  check := true;
end;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(t, n);
  for k := 1 to t do
  begin
    read(a, c, c, c, c);
    case a of
    'a' :
    begin
      readln(sz);
      inc(len);
      have[len] := false;
      flag := false;
      for i := 1 to n - sz + 1 do
      begin
        if check(i, sz) then
        begin
          for j := 1 to sz do
            used[i + j - 1] := true;
          have[len] := true;
          st[len] := i;
          sb[len] := sz;
          bl[i] := len;
          writeln(len);
          flag := true;
          break;
        end;
      end;
      if not flag then
      begin
        writeln('NULL');
        dec(len);
      end;
    end;
    'e' :
    begin
      readln(nm);
      if (nm < 1) or (nm > len) then
      begin
        writeln('ILLEGAL_ERASE_ARGUMENT');
        continue;
      end;
      if not have[nm] then
        writeln('ILLEGAL_ERASE_ARGUMENT')
      else
      begin
        for i := 1 to sb[nm] do
          used[st[nm] + i - 1] := false;
        have[nm] := false;
        bl[st[nm]] := 0;
      end;
    end;
    'd' :
    begin
      readln(line);
      p := 0;
      for i := 1 to n do
        if bl[i] <> 0 then
        begin
          inc(p);
          b := bl[i];
          st[b] := p;
          bl[i] := 0;
          bl[p] := b;
          for j := 1 to sb[b] do
          begin
            used[i + j - 1] := false;
            used[p] := true;
            inc(p);
          end;
          dec(p);
        end;
    end;
  end;
  end;
end.