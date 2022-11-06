var
  a:array[1..100]of longint;
  n,c,i,ans:longint;
begin
  readln(n,c);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
    if a[i]-a[i+1]-c>ans then
      ans:=a[i]-a[i+1]-c;
  writeln(ans);
end.