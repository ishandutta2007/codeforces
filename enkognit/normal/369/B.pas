var
 a : array[0..32000] of longint;
 f : array[0..1000] of boolean;
 yy,n,m,l,e,u,t,k,x,y,z,r,min,p,sall,sk : longint;
 i,j : longint;
 h : real;
 s,s1 : string;
 f1 : boolean;
begin
  read(n,k,l,r,sall,sk);

  for i:=1 to sk mod k do
  write(sk div k+1,' ');

  for i:=1 to k-(sk mod k) do
  write(sk div k,' ');
  y:=n-k;
  if n=k then halt;
  for i:=1 to (sall-sk) mod (y) do
  write((sall-sk) div (y)+1,' ');

  for i:=1 to y-((sall-sk) mod y) do
  write((sall-sk) div (y),' ');
  writeln;
end.