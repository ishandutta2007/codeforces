var t,x,y,p,r:int64;
begin
  readln(t);
  while t>0 do begin
    dec(t);readln(x,y);
    r:=0;p:=1 shl 61;
    while true do begin
      if (x<=p-1)and(y>=p-1) then begin
        writeln(r+p-1);break;
      end;
      inc(r,x-(x mod p));
      x:=x mod p;y:=y mod p;
      p:=p shr 1;
    end;
  end;
end.