var
  a,b,c,x,p,n:int64;
  i,j:longint;
  sl:array[1..100]of int64;
procedure ck(x,y:int64);inline;
var w,z:int64;
begin
  z:=0;w:=x;
  while x>0 do begin
    inc(z,x mod 10);
    x:=x div 10;
  end;
  if y=z then begin
    inc(n);sl[n]:=w;
  end;
end;
begin
  readln(a,b,c);
  for i:=1 to 100 do begin
    p:=i;x:=1;
    for j:=1 to a do x:=x*p;
    x:=x*b+c;
    if (x>0)and(x<1000000000) then ck(x,i);
  end;
  writeln(n);
  for i:=1 to n do write(sl[i],' ');
  writeln;
end.