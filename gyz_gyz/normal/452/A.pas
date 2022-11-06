const a:array[1..6]of string=('jolteon','flareon','umbreon','leafeon','glaceon','sylveon');
var
  s:string;
  n,i,j:longint;
begin
  readln(n);readln(s);
  if n=6 then begin
    writeln('espeon');exit;
  end;
  if n=8 then begin
    writeln('vaporeon');exit;
  end;
  for i:=1 to 6 do
    for j:=1 to 8 do begin
      if j=8 then begin
        writeln(a[i]);exit;
      end;
      if (s[j]<>'.')and(a[i,j]<>s[j]) then break;
    end;
end.