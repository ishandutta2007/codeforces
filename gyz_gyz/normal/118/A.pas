var
  s:string;
  i:longint;
begin
  readln(s);
  for i:=1 to length(s) do begin
    s[i]:=lowercase(s[i]);
    if (s[i]='a')or(s[i]='o')or
    (s[i]='y')or(s[i]='e')or
    (s[i]='u')or(s[i]='i') then continue;
    write('.',s[i]);
  end;
  writeln;
end.