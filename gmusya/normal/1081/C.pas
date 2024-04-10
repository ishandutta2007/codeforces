var n,m,k,i,j: longint;
    a: array [1..2001, 1..2001] of int64;
    nuzhn: int64;

begin
  readln (n,m,k);
  a[1,1]:=1;
  for i:=2 to n do for j:=1 to i do
  begin
    if j=1 then a[i,j]:=1 else
    a[i,j]:=(a[i-1,j-1]+a[i-1,j]) mod 998244353;
  end;
  nuzhn:=a[n,k+1];
  nuzhn:=(nuzhn*m) mod 998244353;
  for i:=1 to k do nuzhn:=nuzhn*(m-1) mod 998244353;
  writeln (nuzhn);
end.