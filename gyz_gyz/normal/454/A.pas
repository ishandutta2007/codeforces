var n,i,j:longint;
begin
  readln(n);
  for i:=1 to n do begin
    for j:=1 to abs(n div 2-i+1) do write('*');
    for j:=1 to n-abs(i-n div 2-1)*2 do write('D');
    for j:=1 to abs(n div 2-i+1) do write('*');
    writeln;
  end;
end.