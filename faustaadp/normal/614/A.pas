program dlinkcuttreelin;
var
l,r,k,has:uint64;
i,j:longint;
hon:boolean;

begin
 readln(l,r,k);
 hon:=false;
 if l=1 then begin
  write('1 ');
  hon:=true;
 end;
  has:=1;
  for i:=1 to 100000 do begin
   has:=has*k;
   if (has >= l) and (has<=r) then begin
    write(has,' ');
    hon:=true;
   end;
   if (has>=r) or (1000000000000000000/k<has) then
    break;
  end;
  if hon=false then begin
    writeln('-1');
  end;
end.