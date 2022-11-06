var
  n,k,i:longint;
begin
  readln(n,k);
  if k and 1=0 then begin
    for i:=1 to k do
      if i and 1=1 then write((k shr 1)+(i shr 1)+1,' ') else write((k shr 1)-(i shr 1)+1,' ');
    for i:=k+1 to n do write(i,' ');writeln;
  end else begin
    for i:=1 to k do
      if i and 1=1 then write((k shr 1)-(i shr 1)+1,' ') else write((k shr 1)+(i shr 1)+1,' ');
    for i:=k+1 to n do write(i,' ');writeln;
  end;
end.