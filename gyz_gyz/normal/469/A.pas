var
  a:array[1..100]of boolean;
  n,p,x,i:longint;
begin
  readln(n);read(p);
  for i:=1 to p do begin
    read(x);a[x]:=true;
  end;
  read(p);
  for i:=1 to p do begin
    read(x);a[x]:=true;
  end;
  for i:=1 to n do
    if not(a[i]) then begin
      writeln('Oh, my keyboard!');halt;
    end;
  writeln('I become the guy.');
end.