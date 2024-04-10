var str: ansistring;
    i, ans, n: longint;
begin
  readln(str);
  n := length(str);
  for i := 1 to n - 1 do str := str + '0';
  for i := 1 to length(str) do ans := (ans * 2 + ord(str[i]) - ord('0')) mod 1000000007;
  write(ans);
end.