var
 n,i,has,j,p,k:longint;
 x,y:array[0..1000] of longint;


procedure swap( var a, b:longint );
var
  temp : longint;
begin
  temp := a;
  a := b;
  b := temp;
end;





begin
 readln(k);
 for i:=1 to 12 do
  read(x[i]);
 readln;

 for i:=1 to 11 do
    begin
     for j:=i+1 to 12 do
      begin
       if x[j] > x[i] then
        swap(x[j],x[i]);
      end;
    end;

// for i:=1 to 12 do
 // write(x[i]);
 //writeln;
// for i:=1 to 12 do begin
while (has<k) and (p<13) do begin
  inc(p);
  has:=x[p]+has;
  //writeln(has);
 end;
 if has>=k then
  writeln(p) else
  writeln('-1');
 //readln;
end.