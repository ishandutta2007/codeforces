const maxV = 1234567;

var
  n, i, v: longint;
  cnt, dp: array [1 .. maxV] of longint;

begin
  readln(n);
  for i := 1 to n do
  begin
    read(v);
    inc(cnt[v]);
  end;
  for i := maxV downto 1 do
  begin
    v := i + i;
    while v <= maxV do
    begin
      if dp[v] > dp[i] then dp[i] := dp[v];
      inc(v, i);
    end;
    inc(dp[i], cnt[i]);
  end;
  write(dp[1]);
end.