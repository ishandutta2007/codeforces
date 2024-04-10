var
  k,n1,n2,n3,t1,t2,t3,i:longint;
  a:array[1..10000]of longint;
function max(x,y:longint):longint;inline;
begin
  if x>y then exit(x) else exit(y);
end;
begin
  readln(k,n1,n2,n3,t1,t2,t3);
  for i:=1 to k do begin
    if i-n1>0 then a[i]:=max(a[i],a[i-n1]+t1);
    if i-n2>0 then a[i]:=max(a[i],a[i-n2]+t2);
    if i-n3>0 then a[i]:=max(a[i],a[i-n3]+t3);
  end;
  writeln(a[k]+t1+t2+t3);
end.