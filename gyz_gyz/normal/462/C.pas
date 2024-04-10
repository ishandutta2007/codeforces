var
  a:array[1..300000]of int64;
  n,i:longint;
  ans:int64;
    procedure sort(l,r: longint);
      var
         i,j: longint;
         x,y:int64;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  for i:=1 to n do inc(ans,a[i]*(i+1));
  writeln(ans-a[n]);
end.