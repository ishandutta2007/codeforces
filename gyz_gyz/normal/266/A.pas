var
  a:array[1..100]of longint;
  n,i,j,ans:longint;
  s:string;
begin
  readln(n);readln(s);
  for i:=1 to n do a[i]:=i-1;
  for i:=1 to n do
    for j:=1 to i-1 do
      if s[i]<>s[j] then
        if a[j]+i-j-1<a[i] then
          a[i]:=a[j]+i-j-1;
  ans:=n;
  for i:=1 to n do
    if a[i]+n-i<ans then ans:=a[i]+n-i;
  writeln(ans);
end.