var
s:array [1..30] of string[255];
c:string;
i,j,m,n,p,k:longint;
f:boolean;
begin
readln(n);
for i:=1 to n do
readln(s[i]);
for i:=1 to 26 do
 begin
 f:=false;
 c:='';
 c:=chr(ord('a')+i-1);
 for j:=1 to n do
   begin
   p:=pos(c,s[j]);
   if (p<>0) then begin f:=true; break; end;
    end;
 if f=false then begin writeln(c); exit; end;
 end;
for i:=1 to 26 do
 for j:=1 to 26 do
  begin
  f:=false;
  c:=chr(ord('a')+i-1);
  c:=c+chr(ord('a')+j-1);
  for k:=1 to n do
   begin
   p:=pos(c,s[k]);
   if (p<>0) then begin f:=true; break; end;
   end;
  if f=false then begin writeln(c); exit; end;
 end;
end.