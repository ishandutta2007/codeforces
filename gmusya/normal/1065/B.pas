var i,o,n,m: int64;
begin
  read (n,m);
  if m>0 then
  begin
    o:=0;
    while o<m do
    begin
      i:=i+1;
      o:=o+i;
    end;
  if n-m*2>0 then writeln (n-m*2, ' ', n-i-1) else writeln (0, ' ', n-i-1);
  end else writeln (n, ' ', n);
end.