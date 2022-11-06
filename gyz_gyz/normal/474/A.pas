const st:string='qwertyuiopasdfghjkl;zxcvbnm,./';
var
  s:string;
  i,j:longint;
  c:char;
begin
  readln(c);readln(s);
  for i:=1 to length(s) do
    for j:=1 to 30 do
      if st[j]=s[i] then begin
        if c='R' then s[i]:=st[j-1] else s[i]:=st[j+1];
        break;
      end;
  writeln(s);
end.