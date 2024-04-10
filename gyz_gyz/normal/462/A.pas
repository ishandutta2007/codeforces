var
  a:array[0..200,0..200]of longint;
  n,i,j:longint;
  c:char;
begin
  readln(n);
  for i:=1 to n do begin
    for j:=1 to n do begin
      read(c);
      if c='o' then a[i,j]:=1;
    end;
    readln;
  end;
  for i:=1 to n do
    for j:=1 to n do
      if (a[i,j-1]+a[i-1,j]+a[i,j+1]+a[i+1,j]) mod 2=1 then begin
        writeln('NO');exit;
      end;
  writeln('YES');
end.