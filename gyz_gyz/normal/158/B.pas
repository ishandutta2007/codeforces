var
  a:array[1..4]of longint;
  n,i,x,ans:longint;
begin
  readln(n);
  for i:=1 to n do begin
    read(x);inc(a[x]);
  end;
  inc(ans,a[4]);
  inc(ans,a[3]);
  dec(a[1],a[3]);
  if a[1]<0 then a[1]:=0;
  inc(ans,a[2] shr 1);
  a[2]:=a[2] and 1;
  if a[2]>0 then begin
    dec(a[1],2);inc(ans);
  end;
  if a[1]<0 then a[1]:=0;
  inc(ans,a[1] shr 2);
  a[1]:=a[1] and 3;
  if a[1]>0 then inc(ans);
  writeln(ans);
end.