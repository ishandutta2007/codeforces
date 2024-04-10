var
  a,b:array[1..50]of longint;
  n,m,i,j,p,ans:longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  readln(m);
  for i:=1 to m do read(b[i]);
  for i:=1 to n do
    for j:=1 to m do
      if b[j] mod a[i]=0 then begin
        if b[j] div a[i]=p then inc(ans);
        if b[j] div a[i]>p then begin
          p:=b[j] div a[i];ans:=1;
        end;
      end;
  writeln(ans);
end.