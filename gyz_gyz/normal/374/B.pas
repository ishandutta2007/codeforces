var
  c,cc,ccc:char;
  ans,p,s:int64;
begin
  ans:=1;p:=1;
  while not(eof) do begin
    ccc:=cc;cc:=c;read(c);
    if (ord(c)+ord(cc)-ord('0')=ord('9'))then begin
      if (s=0)and(c=ccc) then begin
        s:=1;inc(p);
      end else s:=0;
    end else begin
      if s=1 then ans:=ans*p;
      p:=1;s:=0;
    end;
  end;
  writeln(ans);
end.