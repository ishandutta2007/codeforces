var
 s,t,sp:string;
 i:longint;

begin
 readln(s);
 sp:=' ';
 t:='WUB';
 while pos(t,s)>0 do begin
 // writeln(pos(t,s));

 //if (s[pos(t,s)] <> ' ')  then
  insert(sp,s,pos(t,s));
    delete(s,pos(t,s),3);
 end;
 {for i:=1 to length(s) do begin
  if (s[i]=' ') and (s[i+1]=' ') then
   delete(s,i,1);
 end;  }
 writeln(s);
//readln;
end.