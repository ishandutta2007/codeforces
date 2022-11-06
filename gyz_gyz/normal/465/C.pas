var
  s:string;
  n,m,i:longint;
begin
  readln(n,m);readln(s);i:=n;
  while (i>0)and(ord(s[i])-96=m) do dec(i);
  if i=0 then begin
    writeln('NO');halt;
  end;
  s[i]:=chr(ord(s[i])+1);
  while i<=n do begin
    if (i>1)and(s[i]=s[i-1])or(i>2)and(s[i]=s[i-2]) then begin
      while (i>0)and(ord(s[i])-96=m) do dec(i);
      if i=0 then begin
        writeln('NO');halt;
      end;
      s[i]:=chr(ord(s[i])+1);
    end else begin
      inc(i);s[i]:='a';
    end;
  end;
  writeln(s);
end.