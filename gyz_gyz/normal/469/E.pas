var a,b,c,d:qword;
begin
  read(a);d:=a;c:=1;
  while d>0 do begin
    inc(b);d:=d div 10;c:=c*10;
  end;
  d:=45*b;
  while (b>1)or(d>=a) do
    if d<a then begin
      dec(b);d:=d*10;
    end else dec(d,a);
  writeln(a-d,' ',c+a-d-1);
end.