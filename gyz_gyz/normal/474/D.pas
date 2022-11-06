var
  a:array[0..100000]of int64;
  k:int64;
  n,i,x,y:longint;
begin
  readln(n,k);
  for i:=0 to k-1 do a[i]:=1;
  for i:=k to 100000 do
    a[i]:=(a[i-k]+a[i-1]) mod 1000000007;
  for i:=1 to 100000 do a[i]:=(a[i]+a[i-1]) mod 1000000007;
  for i:=1 to n do begin
    readln(x,y);
    writeln((a[y]+1000000007-a[x-1]) mod 1000000007);
  end;
end.