var m,z,n,r,k,i,j,ij: int64;
    a,b: array [1..100000] of longint;
begin
  readln (n,r);
  for i:=1 to n do read (a[i]);
  for i:=n+1 to n+10*r do a[i]:=0;
  for i:=1 to n+2*r do b[i]:=0;
  i:=1;
  k:=0;
  while i<=n do
  begin
    j:=i+r-1;
    if j<1 then j:=1;
    m:=0;
    while (m=0) and (j>0) and (j<=i+r-1) and (j>=i-r+1) do
    begin
      if a[j]=1 then
      begin
        m:=1;
        ij:=j+r-1;
        k:=k+1;
        i:=ij;
        while (ij<=j+r-1) and (ij>=j-r+1) and (ij>0) do 
        begin
          b[ij]:=1;
          ij:=ij-1;
        end;
      end;
      j:=j-1;
    end;
  i:=i+1;
  end;
  for i:=1 to n do if b[i]=0 then z:=1;
  if z=1 then writeln ('-1') else writeln (k);
end.