program football;
var
s:string;
b:boolean;
i,j,t:longint;

begin
 readln(s);
 b:=false;
 for i:=1 to length(s)-6 do begin
  t:=0;
  for j:=i+1 to i+6 do begin
   if s[i]=s[j] then begin
    t:=t+1;
   end;
   if t=6 then begin
    b:=true;
   end;
  end;
 end;
 if b=true then
  writeln('YES')
 else
  writeln('NO');
end.