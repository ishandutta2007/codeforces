var
 a:array[0..10000] of longint;
 n,i,j,m,l,u,t,k,x,y,z : longint;
 h : real;
 f1,f2 : boolean;
begin
 { assign(input,'happy.in');
  assign(output,'happy.out');
  reset(input);
  rewrite(output);  }
  readln(n,m,l);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
   if a[i]=1 then k:=k+1 else
   if a[i]=2 then t:=t+1;
   if k>m then
   begin
    x:=x+k-m;
    m:=0;
   end else
   if k<=m then
    m:=m-k;
    if t>m+l then
   begin
    x:=x+t-(l+m);
    t:=t-(m+l);
   end else
   l:=l+m-t;
   writeln(x);
end.