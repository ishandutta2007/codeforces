var
  n,i:longint;
  x:char;
begin
  readln(n);
  for i:=1 to n do begin
    read(x);
    if x='0' then begin
      writeln(i);exit;
    end;
  end;
  writeln(n);
end.