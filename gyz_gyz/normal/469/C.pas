var
  n,i,x:longint;
begin
  readln(n);
  if n>6 then begin
    writeln('YES');x:=n;
    for i:=n-1 downto 3 do
      if x>24 then begin
        writeln(x,' - ',i,' = ',x-i);x:=x-i;
      end else begin
        writeln(x,' + ',i,' = ',x+i);x:=x+i;
      end;
    if x=22 then begin
      writeln('22 + 2 = 24');
      writeln('24 * 1 = 24');
    end;
    if x=23 then begin
      writeln('23 + 2 = 25');
      writeln('25 - 1 = 24');
    end;
    if x=24 then begin
      writeln('2 - 1 = 1');
      writeln('24 * 1 = 24');
    end;
    if x=25 then begin
      writeln('25 - 2 = 23');
      writeln('23 + 1 = 24');
    end;
    if x=26 then begin
      writeln('26 - 2 = 24');
      writeln('24 * 1 = 24');
    end;
    if x=27 then begin
      writeln('27 - 2 = 25');
      writeln('25 - 1 = 24');
    end;
  end;
  if n=6 then begin
    writeln('YES');
    writeln('6 * 4 = 24');
    writeln('5 * 1 = 5');
    writeln('5 - 3 = 2');
    writeln('2 - 2 = 0');
    writeln('24 + 0 = 24');
  end;
  if n=5 then begin
    writeln('YES');
    writeln('5 + 1 = 6');
    writeln('6 * 4 = 24');
    writeln('3 - 2 = 1');
    writeln('24 * 1 = 24');
  end;
  if n=4 then begin
    writeln('YES');
    writeln('4 * 3 = 12');
    writeln('12 * 2 = 24');
    writeln('24 * 1 = 24');
  end;
  if n<4 then writeln('NO');
end.