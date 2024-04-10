var
  a : array[1..100]of longint;
  n,m,i,j,k,l,r,q : longint;

  procedure sfr(l,r : longint);
  var i,j,e,x : longint;
  begin
   i:=l;
   j:=r;
   x:=a[(l+r) shr 1];
   repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
     e:=a[i];
     a[i]:=a[j];
     a[j]:=e;
     inc(i);
     dec(j);
    end;
   until i>j;
   if l<j then sfr(l,j);
   if i<r then sfr(i,r);
  end;
begin
 { assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);   }
  readln(n);
  for i:=1 to n do read(a[i]);
  sfr(1,n);
  for i:=1 to n do write(a[i],' ');
end.