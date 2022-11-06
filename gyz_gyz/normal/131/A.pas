var
  s:string;
  i,u:longint;
begin
  readln(s);
  for i:=2 to length(s) do
    if lowercase(s[i])=s[i] then begin
      u:=1;break;
    end;
  if u=0 then
    for i:=2 to length(s) do
      s[i]:=lowercase(s[i]);
  if u=0 then
    if lowercase(s[1])=s[1] then s[1]:=upcase(s[1])
    else s[1]:=lowercase(s[1]);
  writeln(s);
end.