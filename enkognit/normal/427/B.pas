var
 a : array[0..200001] of longint;
 n,m,t,k,i,j,l,r,z : longint;
begin
{ assign(input,'input.txt');
 reset(input);
 assign(output,'output.txt');
 rewrite(output);}
 readln(n,m,k);
 for i:=1 to n do read(a[i]);
 i:=0;
 a[n+1]:=m+1;
 a[0]:=m+1;
 while i<=n do
 begin
  l:=0;
  j:=i+1;
  for j:=i+1 to n+1 do
   if a[j]>m then
   begin
    if j-i-1>=k then
    r:=r+(j-i-1-k)+1;
    i:=j;
    break;
   end;
 end;
 writeln(r);
end.