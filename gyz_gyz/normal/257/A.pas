var
  n,m,k,i,j:longint;
  a:array[1..1000]of longint;
    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]>x do
            inc(i);
           while x>a[j] do
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
  readln(n,m,k);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  if m<=k then begin
    writeln(0);exit;
  end;
  for i:=1 to n do begin
    inc(k,a[i]-1);
    if m<=k then begin
      writeln(i);exit;
    end;
  end;
  writeln(-1);
end.