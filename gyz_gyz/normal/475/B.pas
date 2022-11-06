var
  a:array[1..500,1..500]of longint;
  n,m,s,i,j,k:longint;
  c:char;
begin
  readln(n,m);s:=n*m;
  for i:=1 to n do begin
    read(c);
    if c='>' then
      for j:=1 to m-1 do
        a[(i-1)*m+j,(i-1)*m+j+1]:=1
    else
      for j:=2 to m do
        a[(i-1)*m+j,(i-1)*m+j-1]:=1;
  end;
  readln;
  for j:=1 to m do begin
    read(c);
    if c='v' then
      for i:=1 to n-1 do
        a[(i-1)*m+j,i*m+j]:=1
    else
      for i:=2 to n do
        a[(i-1)*m+j,(i-2)*m+j]:=1;
  end;
  for k:=1 to s do
    for i:=1 to s do
      for j:=1 to s do
        if (i<>j)and(i<>k)and(k<>j)and
        (a[i,k]=1)and(a[k,j]=1) then a[i,j]:=1;
  for i:=1 to s do
    for j:=1 to s do
      if i<>j then
        if a[i,j]=0 then begin
          writeln('NO');halt;
        end;
  writeln('YES');
end.