var l,swap, kb,j,n,an,a,b,k,i: int64;
    q, aq,bq: array [0..10000000] of int64;
begin
  readln (a,b);
  swap:=0;
  if (a>b) then
  begin
    k:=a;
    a:=b;
    b:=k;
    swap:=1;
  end;
  k:=0;
  i:=0;
  while k<=a+b do
  begin
    i:=i+1;
    k:=k+i;
    q[i]:=1;
  end;
  n:=i-1;
  k:=0;
  i:=0;
  while (k+i+1<=a) do
  begin
    i:=i+1;
    k:=k+i;
    q[i]:=0;
    aq[i]:=i;
  end;
  l:=a-k;
  an:=i;
  for i:=an downto 1 do
  begin
    if l>0 then
    begin
      q[aq[i]]:=1;
      aq[i]:=aq[i]+1;
      q[aq[i]]:=0;
    end;
    l:=l-1;
  end;
  kb:=0;
  i:=0;
  j:=1;
  while (kb<=b) do
  begin
    i:=i+1;
    if q[i]=1 then
    begin
      q[i]:=0;
      bq[j]:=i;
      b:=b-i;
      j:=j+1;
    end;
  end;
  if swap=0 then
  begin
    writeln (an);
    for i:=1 to an do write (aq[i], ' ');
    if a>0 then writeln;
    writeln (j-2);
    for i:=1 to j-2 do write (bq[i], ' ');
  end else
  begin
    writeln (j-2);
    for i:=1 to j-2 do write (bq[i], ' ');
    if j-2>0 then writeln;
    writeln (an);
    for i:=1 to an do write (aq[i], ' ');
  end;
end.