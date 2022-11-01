var n,i,total: int64  ;
    a: array [1..200000] of int64;
    b: array [1..100000, 1..2] of int64;

begin
  readln (n);
  for i:=1 to 2*n do read (a[i]);
  for i:=1 to 2*n do 
  begin
    if b[a[i],1]=0 then b[a[i],1]:=i else
    b[a[i],2]:=i;
  end;
  for i:=1 to n-1 do total:=total+min(abs(b[i,1]-b[i+1,1])+abs(b[i,2]-b[i+1,2]),abs(b[i,2]-b[i+1,1])+abs(b[i,1]-b[i+1,2]));
  writeln (total+b[1,1]+b[1,2]-2);
end.