var
  a:array[0..100000]of boolean;
  x,y:longint;
begin
  readln(x,y);
  while not(a[x]) do begin
    if x=0 then begin
      writeln('Yes');halt;
    end;
    a[x]:=true;x:=(x*2) mod y;
  end;
  writeln('No');
end.