var
 a,b :array[1..200000] of longint;
 k,n,l,i,m,j : longint;
begin
{  assign(f,'input.txt');
  reset(f);
  assign(f1,'output.txt');
  rewrite(f1); }
  readln(n,m);
  for i:=1 to n do
  begin
   read(a[i]);
   inc(b[a[i]]);
   l:=l+(b[a[i]]-1);
   k:=k+(n-i);
  end;
   writeln(k-l);
end.