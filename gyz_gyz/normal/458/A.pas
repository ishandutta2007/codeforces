const mx=150000;
var
  s:ansistring;
  a,b:array[1..200000]of longint;
  i,j,l:longint;
begin
  readln(s);l:=length(s);
  for i:=mx downto mx-l+1 do
    if s[i+l-mx]='1' then a[i]:=1;
  readln(s);l:=length(s);
  for i:=mx downto mx-l+1 do
    if s[i+l-mx]='1' then b[i]:=1;
  for i:=1 to mx do begin
    j:=i;
    while a[j+1]*a[j+2]>0 do begin
      inc(a[j]);dec(a[j+1]);dec(a[j+2]);dec(j,2);
    end;
    j:=i;
    while b[j+1]*b[j+2]>0 do begin
      inc(b[j]);dec(b[j+1]);dec(b[j+2]);dec(j,2);
    end;
  end;
  for i:=1 to mx do begin
    if a[i]<b[i] then begin
      writeln('<');exit;
    end;
    if b[i]<a[i] then begin
      writeln('>');exit;
    end;
  end;
  writeln('=');
end.