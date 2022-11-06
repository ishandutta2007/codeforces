var
  a:array[0..2000,0..2000]of longint;
  b:array[1..2000]of longint;
  s1,s2:ansistring;
  n,m,i,j,k:longint;
begin
  readln(s1);n:=length(s1);
  readln(s2);m:=length(s2);
  for i:=1 to n do
    if s1[i]=s2[1] then begin
      k:=1;
      for j:=i to n do
        if s1[j]=s2[k] then begin
          inc(k);if k>m then break;
        end;
      if k>m then b[i]:=j;
    end;
  for i:=0 to n-1 do
    for j:=0 to i do begin
      if a[i,j]>a[i+1,j] then a[i+1,j]:=a[i,j];
      if a[i,j]>a[i+1,j+1] then a[i+1,j+1]:=a[i,j];
      if (b[i+1]>0)and(a[i,j]+1>a[b[i+1],j+b[i+1]-i-m]) then
        a[b[i+1],j+b[i+1]-i-m]:=a[i,j]+1;
    end;
  for i:=0 to n do write(a[n,i],' ');
  writeln;
end.