var
  a,w,c:array[1..100000]of longint;
  s:ansistring;
  n,i,j,ans:longint;
begin
  readln(s);n:=length(s);
  for i:=2 to n do begin
    j:=a[i-1];
    while (j>0)and(s[j+1]<>s[i]) do j:=a[j];
    if s[j+1]=s[i] then a[i]:=j+1 else a[i]:=0;
  end;
  for i:=1 to n do c[i]:=1;
  for i:=n downto 1 do
    if a[i]>0 then inc(c[a[i]],c[i]);
  i:=n;
  while i>0 do begin
    inc(ans);w[ans]:=i;i:=a[i];
  end;
  writeln(ans);
  for i:=ans downto 1 do
    writeln(w[i],' ',c[w[i]]);
end.