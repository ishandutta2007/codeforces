var
  c:char;
  a1,a2,b1,b2,an1,an2,i:int64;
begin
  while not(eof) do begin
    read(c);inc(i);
    if c='a' then begin
      if i and 1=1 then begin
        inc(a1);inc(an1,a1);inc(an2,a2);
      end else begin
        inc(a2);inc(an1,a2);inc(an2,a1);
      end;
    end;
    if c='b' then begin
      if i and 1=1 then begin
        inc(b1);inc(an1,b1);inc(an2,b2);
      end else begin
        inc(b2);inc(an1,b2);inc(an2,b1);
      end;
    end;
  end;
  writeln(an2,' ',an1);
end.