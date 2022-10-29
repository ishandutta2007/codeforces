var
 a :array[1..10000] of longint;
 k,b,n,t,l,i,m,j : longint;
 f,f1 : text;
 sr : real;
begin
{  assign(f,'input.txt');
  reset(f);
  assign(f1,'output.txt');
  rewrite(f1); }
  readln(n,m);
  for i:=1 to n do readln(a[i]);
  for i:=1 to n-1 do
   for j:=i+1 to n do
   if a[i]<a[j] then
   begin
    t:=a[i];
    a[i]:=a[j];
    a[j]:=t;
   end;
  for i:=1 to n do
  begin
   if k>=m then break;
   k:=k+a[i];
   l:=l+1;
  end;
  writeln(l);
end.