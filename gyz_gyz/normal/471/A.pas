var
  a:array[1..9]of longint;
  x,i:longint;
begin
  for i:=1 to 6 do begin
    read(x);inc(a[x]);
  end;
  x:=0;
  for i:=1 to 9 do
    if a[i]>=4 then begin
      dec(a[i],4);inc(x);
    end;
  if x=0 then begin
    writeln('Alien');halt;
  end;
  for i:=1 to 9 do
    if a[i]=2 then inc(x);
  if x=1 then writeln('Bear') else writeln('Elephant');
end.