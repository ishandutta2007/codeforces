var n,x,y,i,num:longint;
    s,t,u:string;

begin
     readln(n);
     readln(s);
     x:=1; y:=0;
     for i:=2 to n do
     begin
          readln(t);
          if s=t then inc(x)
          else
          begin
               u:=t; inc(y);
          end;
     end;
     if x>y then writeln(s)
     else writeln(u);
end.