var
  n, k, i, j, r: longint;
  a: array [1 .. 200000] of array of longint;
  s, q: array [1 .. 200000] of longint;

begin
  readln(n, k);
  r := n - 1;
  for i := 1 to k do
  begin
    q[i] := 0;
    read(s[i]);
    inc(r, s[i] - 1);
    SetLength(a[i], s[i] + 5);
    for j := 1 to s[i] do
    begin
      read(a[i, j]);
      if a[i, j] = j then inc(q[i]);
    end;
    //writeln('q[i] = ', q[i]);
    if q[i] <> 0
       then dec(r, (q[i] - 1) * 2);
  end;
  writeln(r);
end.