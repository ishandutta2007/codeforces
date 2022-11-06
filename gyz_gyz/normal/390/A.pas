var
  a,b:array[0..100]of longint;
  n,i,x,an1,an2:longint;
begin
  readln(n);
  for i:=1 to n do begin
    read(x);a[x]:=1;
    read(x);b[x]:=1;
  end;
  for i:=0 to 100 do begin
    inc(an1,a[i]);inc(an2,b[i]);
  end;
  if an1<an2 then writeln(an1) else writeln(an2);
end.