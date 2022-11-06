var
 n,h,m,maks,i,j:longint;
 a:array[0..24,0..60] of longint;

begin
 readln(n);
 for i:=1 to n do begin
  readln(h,m);
  a[h,m]:=a[h,m]+1;
 end;
 for i:=0 to 24 do begin
  for j:=0 to 60 do begin
   if a[i,j]>maks then
    maks:=a[i,j];
  end;
 end;
 writeln(maks);
 readln;
 end.