var
  a:array[0..20,-20..20]of extended;
  s:string;
  n,ed,i,j:longint;
begin
  readln(s);n:=length(s);
  for i:=1 to n do
    if s[i]='+' then inc(ed) else dec(ed);
  readln(s);a[0,0]:=1;
  for i:=1 to n do begin
    if s[i]='+' then
      for j:=-10 to 10 do
        a[i,j]:=a[i-1,j-1];
    if s[i]='-' then
      for j:=-10 to 10 do
        a[i,j]:=a[i-1,j+1];
    if s[i]='?' then
      for j:=-10 to 10 do
        a[i,j]:=(a[i-1,j+1]+a[i-1,j-1])/2;
  end;
  writeln(a[n,ed]:0:12);
end.