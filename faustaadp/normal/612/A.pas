var
 n,p,q,i,j,x,y,l:longint;
 s:string;

begin
 readln(n,p,q);
 readln(s);
 for i:=0 to (n div p) do begin
  if( n-(i*p)) mod q =0 then begin
   x:=i;
   y:=(n-(i*p)) div q;
   break;
  end;
 end;
// writeln(x,y);
//readln;
if (x=0) and(y=0) then
 writeln('-1')
else begin
writeln(x+y);
for i:=1 to x do begin
 for j:=l+1 to p+l do begin
  write(s[j]);
 end;
 l:=l+p;
 writeln;
end;

for i:=1 to y do begin
 for j:=l+1 to q+l do begin
  write(s[j]);
 end;
 l:=l+q;
writeln;
end;
end;
readln;
end.