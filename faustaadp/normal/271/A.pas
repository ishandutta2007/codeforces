program beautyyear;
var
y:longint;
n,i,j,l:longint;
b:boolean;
a:array[1..4] of longint;

begin
 readln(y);
 for i:=y+1 to 9012 do begin
  b:=true;
  n:=i;
  for j:=1 to 4 do begin
   a[j]:=n mod 10;
   n:=n div 10;
  end;
  for j:=1 to 3 do begin
   for l:=j+1 to 4 do begin
    if a[j]=a[l] then
     b:=false;
   end;
  end;
  if b=true then begin
   writeln(i);
   break;
  end;
 end;
end.