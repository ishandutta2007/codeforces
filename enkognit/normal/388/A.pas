
var
 a,b,c : array[0..10000] of longint;
 aa,bb,z,u,v,x,t,y,i,j,l : longint;
 n,m,k : int64;

 s1 : string;
begin

 { assign(input,'time.in');
  assign(output,'time.out');
  reset(input);
  rewrite(output); }
  readln(n);
  for i:=1 to n do read(a[i]);
  z:=n;

  for i:=1 to n do
  begin
   for j:=i+1 to n do
    if a[i]>a[j] then
    begin
    t:=a[i];
    a[i]:=a[j];
    a[j]:=t;
    end;
  end;
  for i:=1 to n do
  begin
   l:=1;
   k:=a[i];
   for j:=1 to n do
    if ((a[j]>k)or(a[j]>=l))and(b[j]=0) then
    begin
     b[j]:=1;
     l:=l+1;
     k:=a[j];
    end;
    z:=z-l;
    y:=y+1;
    if z<=0 then
    begin
     writeln(y);
     halt;
    end;
  end;

end.