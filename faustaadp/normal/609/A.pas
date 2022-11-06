var
 n,i,has,j,p,k:longint;
 x,y:array[0..10000] of longint;


procedure swap( var a, b:longint );
var
  temp : longint;
begin
  temp := a;
  a := b;
  b := temp;
end;





begin
 readln(n);
 readln(k);
 for i:=1 to n do
  readln(x[i]);

 for i:=1 to n-1 do
    begin
     for j:=i+1 to n do
      begin
       if x[j] > x[i] then
        swap(x[j],x[i]);
      end;
    end;

// for i:=1 to 12 do
 // write(x[i]);
 //writeln;
// for i:=1 to 12 do begin
while (has<k)  do begin
  inc(p);
  has:=x[p]+has;
  //writeln(has);
 end;
  writeln(p);
 readln;
end.