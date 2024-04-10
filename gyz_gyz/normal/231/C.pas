var
  a,b:array[0..100000]of int64;
  n,m,an1,an2:int64;
  i,j:longint;

    procedure sort(l,r: int64);
      var
         i,j,x,y: int64;
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
  readln(n,m);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  for i:=1 to n do b[i]:=b[i-1]+a[i];
  j:=1;an1:=1;an2:=a[1];
  for i:=2 to n do begin
    while (i-j)*a[i]-(b[i-1]-b[j-1])>m do inc(j);
    if i-j+1>an1 then begin
      an1:=i-j+1;an2:=a[i];
    end;
  end;
  writeln(an1,' ',an2);
end.