var
  a,b:array[1..100000]of int64;
  n,x,ans:int64;
  i:longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do begin
    x:=b[i] shr 1;
    if (x<=0)or(b[i]-x>a[i]) then dec(ans) else inc(ans,x*(b[i]-x));
  end;
  writeln(ans);
end.