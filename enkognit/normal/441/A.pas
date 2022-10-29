
var
 b,a,q,w : array[1..100] of longint;
 c : array[1..100,1..100] of longint;
 n,m,e,l,u,t,k,x,y,z,min,p : longint;
 i,j : longint;
 h : real;
 s,s1 : string;
 f1,f : boolean;
begin
 { assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);            }
  m:=0;
  readln(n,l);
  for i:=1 to n do
  begin
   read(k);
   for j:=1 to k do
   begin
    read(x);
    if x<l then
    begin
     m:=m+1;
     a[m]:=i;
     break;
    end;
   end;
   readln;
  end;
  writeln(m);
  for i:=1 to m do write(a[i],' ');
end.