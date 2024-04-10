{$B-}{$H+}

var
  s, res: string;
  p, wp, i, m: longint;
  q, t: int64;
begin
  p := 1; q := 0;
  readln(s);
  while p <= length(s) do
  begin
    while (p <= length(s)) and (s[p] in ['a' .. 'z']) do inc(p);
    wp := p;
    t := 0;
    while (p <= length(s)) and (s[p] in ['0' .. '9', '.']) do
    begin
      if s[p] <> '.'
        then t := t * 10 + (ord(s[p]) - ord('0'));
      inc(p);
    end;
    if (p - wp < 3) or (s[p - 3] <> '.') then t := t * 100;
    inc(q, t);
  end;
  str(q div 100, res);
  m := length(res) mod 3;
  for i := length(res) downto 1 do
    if (i <> length(res)) and (i mod 3 = m)
      then insert('.', res, i+1);
  write(res);
  case q mod 100 of
    0: writeln;
    1 .. 9: writeln('.0', q mod 100);
    10 .. 99: writeln('.', q mod 100);
  end;
end.