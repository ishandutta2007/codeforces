var
 a : array[0..200001] of longint;
 n,m,t,k,i,j,l,r,z : longint;
begin
{ assign(input,'input.txt');
 reset(input);
 assign(output,'output.txt');
 rewrite(output);}
 readln(n);
 for i:=1 to n do
 begin
  read(a[i]);

  m:=m+a[i];
  if (m=1)and(a[i]=1)and(l=0) then
  begin
   k:=i;
   l:=1;
  end;
 end;
 if m>0 then r:=1;
 m:=m-1;
 a[n+1]:=0;
 a[0]:=0;
 while m>0 do
 begin
  for i:=k+1 to n do
   if (a[i]=1)and (i-k=1) then
   begin
    m:=m-1;
    r:=r+1;
    k:=i;
    break;
   end else
   if (a[i]=1)and(i-k>1) then
   begin
    m:=m-1;
    r:=r+2;
    k:=i;
   break;
   end;
  end;
 writeln(r);
end.