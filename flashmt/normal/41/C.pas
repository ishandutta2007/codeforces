var s,re:string;
    n,i:longint;

procedure att(s:string;x:longint);
var l:longint;
begin
     delete(s,x,2);
     insert('@',s,x);
     x:=pos('dot',s);
     while x>0 do
     begin
          delete(s,x,3);
          insert('.',s,x);
          x:=pos('dot',s);
     end;
     if s[1]='.' then
     begin
          delete(s,1,1);
          s:='dot'+s;
     end;
     l:=length(s);
     if s[l]='.' then
     begin
          delete(s,l,1);
          s:=s+'dot';
     end;
     if (re='') or (s<re) then re:=s;
end;

begin
     re:='';
     readln(s);
     n:=length(s);
     for i:=2 to n-1 do
         if (s[i]='a') and (s[i+1]='t') then
         begin
              att(s,i);
              break;
         end;
     writeln(re);
end.