var
 t,n,p,nn:int64;
 i:longint;

begin
 readln(t);
 for i:=1 to t do
 begin
  readln(n);
  nn:=n;
  p:=1;
  while nn>0 do begin
   nn:=nn div 2;
   p:=p*2;
  end;
 // writeln(p);
  writeln((((n+1)*n) div 2)-2*(p)+2);
 end;
 //readln;
end.