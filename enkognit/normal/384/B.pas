
var
 b,c : array[1..10000] of longint;
 a : array[1..1000,1..1000] of longint;
 aa,bb,z,u,v,x,t,y,i,j,l : longint;
 n,m,k : int64;

 s1 : string;
begin

 { assign(input,'time.in');
  assign(output,'time.out');
  reset(input);
  rewrite(output); }
  readln(n,m,k);
  for i:=1 to n do
   for j:=1 to m do read(a[i,j]);
   writeln((m*(m-1)) div 2);
   if k=0 then
   begin
   for i:=1 to m-1 do
    for j:=i+1 to m do writeln(i,' ',j);end else
    begin
   for i:=1 to m-1 do
    for j:=i+1 to m do writeln(j,' ',i);end;
  {for i:=1 to m do
   for j:=i+1 to m do
   begin
    l:=0;
    for u:=1 to n do
     if k=0 then
     begin
     if a[u,i]>a[u,j] then
     begin
      t:=a[u,i];
      a[u,i]:=a[u,j];
      a[u,j]:=t;
      if l=0 then
      begin
       y:=y+1;
       b[y]:=i;
       c[y]:=j;
       l:=1;
      end;
     end;
     end else
     begin
     if a[u,i]<a[u,j] then
     begin
      t:=a[u,i];
      a[u,i]:=a[u,j];
      a[u,j]:=t;
      if l=0 then
      begin
       y:=y+1;
       b[y]:=i;
       c[y]:=j;
       l:=1;
      end;
     end;
     end;
     end;
     writeln(y);
     for i:=1 to y do writeln(b[i],' ',c[i]);}
end.