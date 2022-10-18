var n,prv,i,bad,len,cur:longint;
    a:array[0..100000] of longint;

begin
readln(n);
for i:=0 to n-1 do read(a[i]);
prv:=0;
len:=-1;
for i:=1 to n-1 do
begin
  if a[i] <> a[i - 1] then begin
    cur := i - prv;
    prv := i;
    if (len<>-1) and (len<>cur) then bad:=1;
    len := cur;
  end;
end;
cur := n - prv;
if (len<>-1) and (len<>cur) then bad:=1;
if (bad<>1) then println('YES') else println('NO');

end.