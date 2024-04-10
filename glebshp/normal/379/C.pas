
var  c,a,b:array[1..300010] of longint;
     n,x,i,temp,j:longint;
     procedure sort(l,r:longint);
     begin

     i:=l;
     j:=r;
     x:=a[l+random(r-l+1)];
     repeat
      while a[i]<x do inc(i);
      while a[j]>x do dec(j);
      if i<=j then begin
                   temp:=a[i];
                   a[i]:=a[j];
                   a[j]:=temp;
                   temp:=b[i];
                   b[i]:=b[j];
                   b[j]:=temp;
                   inc(i);
                   dec(j);
                   end;
      until i>j;

     if i<r then sort(i,r);
     if l<j then sort(l,j);

     end;
     function max(x,y:longint):longint;
     begin
     if x>y then max:=x else max:=y; end;
begin
//assign(input,'input.txt');
//reset(input);
readln(n);
for i:=1 to n do begin read(a[i]); b[i]:=i; end;
sort(1,n);
x:=1;

for i:=1 to n do begin
                 c[b[i]]:=max(A[i],x);
                 x:=c[b[i]]+1;
                 end;
for i:=1 to n do writeln(c[i]);
end.