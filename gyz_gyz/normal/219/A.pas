var
  a:array[0..25]of longint;
  s:ansistring;
  k,i,j,l:longint;
begin
  readln(k);
  readln(s);
  for i:=1 to length(s) do
    inc(a[ord(s[i])-97]);
  for i:=0 to 25 do
    if a[i] mod k>0 then begin
      writeln(-1);exit;
    end;
  for i:=1 to k do
    for j:=0 to 25 do
      for l:=1 to a[j] div k do write(chr(j+97));
  writeln;
end.