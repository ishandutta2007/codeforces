var b,k,l,i: longint;
    a: array [1..100000] of longint;

begin
  readln (b,k);
  for i:=1 to k do read (a[i]);
  if (b mod 2) = 0 then 
  begin
    if a[k] mod 2 = 0 then writeln ('even') else writeln ('odd');
  end else
  begin
    for i:=1 to k do if a[i] mod 2 = 1 then l:=l+1;
    if l mod 2 = 0 then writeln ('even') else writeln ('odd');
  end;
end.