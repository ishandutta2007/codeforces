var k,i,n: longint;
    l,r: array [1..100] of longint;

begin
  readln (n);
  for i:=1 to n do readln (l[i], r[i]);
  readln (k);
  for i:=1 to n do if k<=r[i] then break;
  writeln (n-(i-1));
end.