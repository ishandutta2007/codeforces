var m,j,i,n: int64;
    a,x: array [1..11] of int64;

begin
  i:=1;
  readln (n);
  while (n>0) do
  begin
    a[i]:=n mod 10;
    n:=n div 10;
    i:=i+1;
  end;
  n:=i-1;
  for i:=1 to n+1 do x[i]:=1;
  for i:=1 to n do x[1]:=x[1]*a[i];
  for i:=2 to n do
  begin
    if a[i-1]<>9 then 
    begin
      a[i-1]:=9;
      if a[i]>0 then a[i]:=a[i]-1;
    end;
    for j:=1 to n-1 do x[i]:=x[i]*a[j];
    if a[n]<>0 then x[i]:=x[i]*a[n];
  end;
  m:=x[1];
  for i:=1 to n+1 do if x[i]>m then m:=x[i];
  writeln (m);
end.