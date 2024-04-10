var
  n,k,i,ans:longint;
  s:ansistring;
begin
  readln(n,k);
  readln(s);
  if k=2 then begin
    for i:=1 to n do
      if ord(s[i]) mod 2-i mod 2=0 then inc(ans);
    if ans*2>=n then begin
      writeln(n-ans);
      for i:=1 to n do write(chr(66-i mod 2));
      writeln;
    end else begin
      writeln(ans);
      for i:=1 to n do write(chr(65+i mod 2));
      writeln;
    end;
    exit;
  end;
  s:=s+' ';
  for i:=2 to n do begin
    if s[i]<>s[i-1] then continue;
    inc(ans);
    s[i]:='A';
    if (s[i+1]<>s[i])and(s[i]<>s[i-1]) then continue;
    s[i]:='B';
    if (s[i+1]<>s[i])and(s[i]<>s[i-1]) then continue;
    s[i]:='C';
  end;
  writeln(ans);
  writeln(s);
end.