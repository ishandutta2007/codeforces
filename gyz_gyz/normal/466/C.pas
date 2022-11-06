var
  a,b:array[0..500000]of int64;
  n,i:longint;
  al,x,ans:int64;
begin
  readln(n);
  for i:=1 to n do begin
    read(a[i]);inc(al,a[i]);
  end;
  if al mod 3>0 then begin
    writeln(0);halt;
  end;
  for i:=1 to n-2 do begin
    inc(x,a[i]);b[i]:=b[i-1];
    if x*3=al then inc(b[i]);
  end;
  x:=0;
  for i:=n downto 3 do begin
    inc(x,a[i]);
    if x*3=al then inc(ans,b[i-2]);
  end;
  writeln(ans);
end.