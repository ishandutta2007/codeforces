var l,mi,n,k,i,m: longint;
    a: array [1..1000] of longint;

begin
  readln (n,k);
  m:=1;
  for i:=1 to k-1 do
  begin
    l:=n div i * k+i;
    if (l div k)*(l mod k)=n then
    begin
      a[m]:=l;
      m:=m+1;
    end;
  end;
  mi:=a[1];
  for i:=2 to m-1 do if a[i]<mi then mi:=a[i];
  writeln (mi);
end.