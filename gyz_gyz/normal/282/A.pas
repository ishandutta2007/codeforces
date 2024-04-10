var
  n,x,i:longint;
  s:string;
begin
  readln(n);
  for i:=1 to n do begin
    readln(s);
    if pos('+',s)=0 then dec(x) else inc(x);
  end;
  writeln(x);
end.