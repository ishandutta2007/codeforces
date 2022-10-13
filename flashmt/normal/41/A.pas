var a,b:string; i,l:longint;
begin
     readln(a); readln(b); l:=length(a);
     if l<>length(b) then
     begin
          writeln('NO');halt;
     end;
     for i:=1 to l do
         if a[i]<>b[l-i+1] then
         begin
          writeln('NO'); halt;
         end;
     writeln('YES');
end.