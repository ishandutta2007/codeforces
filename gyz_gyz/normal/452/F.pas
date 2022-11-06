var
  a,b:array[1..300000]of longint;
  n,i,j,x:longint;
begin
  readln(n);
  for i:=1 to n do begin
    read(a[i]);b[a[i]]:=i;
  end;
  for i:=1 to n do
    for j:=i+1 to i+50 do begin
      if j>n then break;
      x:=a[i]*2-a[j];
      if (x>0)and(x<=n) then
        if b[x]<i then begin
          writeln('YES');exit;
        end;
      x:=a[j]*2-a[i];
      if (x>0)and(x<=n) then
        if b[x]>j then begin
          writeln('YES');exit;
        end;
    end;
  writeln('NO');
end.