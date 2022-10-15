var
  s, ns: string;
  w: array [1 .. 1000] of string;
  wc, i, j: longint;
  c: char;

begin
  readln(s); wc := 0;
  for i := 1 to 1000 do w[i] := '.';
  for i := 1 to length(s) + 1 do
    for c := 'a' to 'z' do
    begin
      ns := s; Insert(c, ns, i);
      for j := 1 to wc + 1 do
        if w[j] = ns then break;
      if j = wc + 1
         then begin
                inc(wc);
                w[wc] := ns;
              end;
    end;
  writeln(wc);
end.