var n,m,k,l,i: int64;
begin
  readln (n,m,k,l);
  i:=(l+k+m-1) div m;
  if i*m>n then writeln ('-1') else writeln (i);
end.