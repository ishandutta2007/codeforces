var n,t,i,z,l,all: int64;
    a: array[1..200000] of int64;

begin
  readln (n,t);
  for i:=1 to n do read (a[i]);
  for i:=1 to n do l:=l+a[i];
  z:=n;
  i:=1;
  while (t>0) and (l>0) do
  begin
    if (t>l) and (l>0) then
    begin
      all:=all+(t div l)*z;
      t:=t mod l;
    end;
    while (t>=a[i]) do
    begin
      t:=t-a[i];
      if (a[i]<>0) then all:=all+1;
      if i=n then i:=1 else i:=i+1;
    end;
    l:=l-a[i];
    a[i]:=0;
    if z>0 then z:=z-1 else break;
  end;
  writeln (all);
end.