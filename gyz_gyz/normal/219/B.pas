var
  n,m,s,p:int64;
begin
  readln(n,m);s:=1;
  while n>0 do begin
    if n mod 10=9 then begin
      s:=s*10;n:=n div 10;
    end else begin
      inc(p,s*(n mod 10+1));
      if p>m then begin
        while s>1 do begin
          s:=s div 10;n:=n*10+9;
        end;
        writeln(n);
        exit;
      end;
      s:=s*10;n:=n div 10-1;
    end;
  end;
  while s>1 do begin
    s:=s div 10;write(9);
  end;
  writeln;
end.