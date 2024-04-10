var n,k:longint;
begin
  readln(n,k);
  writeln(((n-1)*6+5)*k);
  while n>0 do begin
    dec(n);writeln((n*6+1)*k,' ',(n*6+2)*k,' ',(n*6+3)*k,' ',(n*6+5)*k);
  end;
end.