var
  s:ansistring;
  a,b:array['1'..'4']of int64;
  i:longint;
  ans:int64;
  c:char;
begin
  for c:='1' to '4' do read(a[c]);
  readln;readln(s);
  for i:=1 to length(s) do inc(b[s[i]]);
  for c:='1' to '4' do inc(ans,a[c]*b[c]);
  writeln(ans);
end.