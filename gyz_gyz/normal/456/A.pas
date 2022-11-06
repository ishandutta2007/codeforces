var
  b,c:array[1..100000]of longint;
  n,i,x,y:longint;
begin
  readln(n);
  fillchar(b,sizeof(b),$7f);
  for i:=1 to n do begin
    read(x);read(y);
    if y<b[x] then b[x]:=y;
    if y>c[x] then c[x]:=y;
  end;
  x:=0;
  for i:=1 to n do
    if c[i]>0 then begin
      if x>b[i] then begin
        writeln('Happy Alex');exit;
      end;
      if c[i]>x then x:=c[i];
    end;
  writeln('Poor Alex');
end.