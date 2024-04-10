var q, i: longint;
    a,b: array [1..10000] of longint;
begin
  readln (q);
  for i:=1 to q do read (b[i], a[i]);
  for i:=1 to q do 
  begin
    if (a[i] mod 2=1) and (b[i] mod 2=1) then writeln (-(a[i]+b[i]) div 2);
    if (a[i] mod 2=1) and (b[i] mod 2=0) then writeln (-(a[i]-b[i]+1) div 2);
    if (a[i] mod 2=0) and (b[i] mod 2=1) then writeln ((a[i]-b[i]+1) div 2);
    if (a[i] mod 2=0) and (b[i] mod 2=0) then writeln ((a[i]+b[i]) div 2);
  end;
end.