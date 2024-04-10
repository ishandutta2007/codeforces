uses math;
const fi='';
var n,s,i,j,x,y,p,q,re,u,uu:longint;
    v,t:Array[1..111,0..111] of longint;
    sl:array[1..111] of longint;

function check(var x,y:longint;v1,v2,u:longint):boolean;
var t:longint;
begin
     check:=false;
     if x=y then
     begin
          t:=x;
          x:=x+u*v1; y:=y+u*v2;
          if t=0 then exit;
          if (x<>y) then check:=true;
     end
     else
     begin
          if x<y then
          begin
               x:=x+u*v1; y:=y+u*v2;
               if x>y then check:=true;
               exit;
          end
          else
          begin
               x:=x+u*v1; y:=y+u*v2;
               if x<y then check:=true;
               exit;
          end;
     end;
end;

begin
     assign(input,fi); reset(input);
     read(n,s);
     for i:=1 to n do
     begin
          read(sl[i]);
          t[i,0]:=0;
          for j:=1 to sl[i] do
          begin
               read(v[i,j],t[i,j]);
               t[i,j]:=t[i,j-1]+t[i,j];
          end;
     end;
     re:=0;
     for i:=1 to n-1 do
       for j:=i+1 to n do
       begin
            x:=0; y:=0;
            p:=1; q:=1;
            uu:=0;
            while (p<=sl[i]) and (q<=sl[j]) do
            begin
                 u:=min(t[i,p],t[j,q]);
                 if u>uu then
                 begin
                      if check(x,y,v[i,p],v[j,q],u-uu) then
                         inc(re);
                 end;
                 if u=t[i,p] then inc(p)
                 else inc(q);
                 uu:=u;
                 if (x>=s) or (y>=s) then break;
            end;
       end;
     writeln(re);
     close(input);
end.