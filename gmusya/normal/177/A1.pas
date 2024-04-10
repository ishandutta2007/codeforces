var i,j,s,n: longint;
    a: array [1..101, 1..101] of longint;

begin
  readln (n);
  for i:=1 to n do for j:=1 to n do read (a[i,j]);
  for i:=1 to n do for j:=1 to n do if (i=j) or (i+j=n+1) or ((n mod 2<>0) and ((i=n div 2+1) or (j=n div 2+1))) then s:=s+a[i,j];
  writeln (s);
end.