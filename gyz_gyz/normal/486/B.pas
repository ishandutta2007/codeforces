var
  a,b:array[1..100,1..100]of boolean;
  n,m,i,j,k,x:longint;
begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do begin
      read(x);b[i,j]:=x=1;
      if x=0 then begin
        for k:=1 to m do a[i,k]:=true;
        for k:=1 to n do a[k,j]:=true;
      end;
    end;
  for i:=1 to n do
    for j:=1 to m do
      if b[i,j] then begin
        x:=0;
        for k:=1 to m do
          if not(a[i,k]) then x:=1;
        for k:=1 to n do
          if not(a[k,j]) then x:=1;
        if x=0 then begin
          writeln('NO');halt;
        end;
      end;
  writeln('YES');
  for i:=1 to n do begin
    for j:=1 to m do
      if a[i,j] then write('0 ')
      else write('1 ');
    writeln;
  end;
end.