var n,m,i,j: longint;
    k: boolean;
    a,b: array [1..500, 1..500] of byte;
    g,v: array [1..500] of longint;

begin
  readln (n,m);
  for i:=1 to n do for j:=1 to m do read (a[i,j]);
  for i:=1 to n do for j:=1 to m do read (b[i,j]);
  for i:=1 to n do for j:=1 to m do
  if a[i,j]<>b[i,j] then 
  begin
    g[i]:=g[i]+1;
    v[j]:=v[j]+1;
  end;
  k:=true;
  for i:=1 to n do if g[i] mod 2 = 1 then k:=false;
  for i:=1 to m do if v[i] mod 2 = 1 then k:=false;
  if k then writeln ('Yes') else writeln ('No');
end.