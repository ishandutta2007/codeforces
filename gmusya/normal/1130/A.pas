var n,i,p,m: longint;
    a: array [1..100] of longint;

begin
  readln (n);
  for i:=1 to n do read (a[i]);
  for i:=1 to n do
  begin
    if a[i]>0 then p:=p+1;
    if a[i]<0 then m:=m+1;
  end;
  if p*2>=n then writeln ('1') else
  if m*2>=n then writeln ('-1') else
  writeln ('0');
end.