uses math;
const fi='';
type ar=array[1..30,1..30] of char;
var a:array[1..6] of string;
    d,l:array[1..6] of longint;
    i,j,m,n,rm,rn:longint;
    s,f:array[1..6] of char;
    b,re,oo:ar;

function comp(a,b:ar;m,n,mm,nn:longint):longint;
var i,j:longint;
begin
     comp:=0;
     for i:=1 to min(m,mm) do
     begin
          for j:=1 to min(n,nn) do
              if a[i][j]<b[i][j] then
              begin
                   comp:=-1; exit;
              end
              else
              begin
                   if a[i][j]>b[i][j] then
                   begin
                        comp:=1; exit;
                   end;
              end;
          if n<nn then
          begin
               comp:=-1; exit;
          end;
          if n>nn then
          begin
               comp:=1; exit;
          end;
     end;
     if m<mm then
     begin
          comp:=-1; exit;
     end;
     if m>mm then
     begin
          comp:=1; exit;
     end;
end;

procedure att(x:longint);
var i,u,v,j:longint;
begin
     if x>6 then
     begin
          if (d[1]=2) and (d[2]=5) and (d[3]=3) and (d[4]=6) and (d[5]=4) then
             x:=x;
          fillchar(b,sizeof(b),'.');
          for i:=1 to 6 do
          begin
               s[i]:=a[d[i],1];
               f[i]:=a[d[i],l[d[i]]];
          end;
          if (s[1]<>s[4]) or (f[1]<>s[5]) or (f[4]<>s[2]) then exit;
          if (f[5]<>s[3]) or (f[3]<>f[6]) or (s[6]<>f[2]) then exit;
          if (l[d[1]]<3) or (l[d[4]]<3) or (l[d[6]]<3) or (l[d[3]]<3) then exit;
          if (l[d[5]]<>l[d[4]]+l[d[6]]-1) or (l[d[2]]<>l[d[1]]+l[d[3]]-1) then exit;
          u:=l[d[4]]; v:=l[d[1]];
          if a[d[2],v]<>a[d[5],u] then exit;
          m:=l[d[5]]; n:=l[d[2]];
          for i:=1 to l[d[1]] do b[1,i]:=a[d[1],i];
          for i:=1 to l[d[4]] do b[i,1]:=a[d[4],i];
          for i:=1 to m do b[i,v]:=a[d[5],i];
          for i:=1 to n do b[u,i]:=a[d[2],i];
          for i:=1 to l[d[3]] do b[m,n-i+1]:=a[d[3],l[d[3]]-i+1];
          for i:=1 to l[d[6]] do b[m-i+1,n]:=a[d[6],l[d[6]]-i+1];
          if comp(re,b,rm,rn,m,n)=1 then
          begin
               re:=b; rm:=m; rn:=n;
          end;
     end;
     for i:=1 to 6 do
         if d[i]=0 then
         begin
              d[i]:=x;
              att(x+1);
              d[i]:=0;
         end;
end;

begin
     assign(input,fi); reset(input);
     for i:=1 to 6 do
     begin
          readln(a[i]);
          d[i]:=0;
          l[i]:=length(a[i]);
     end;
     close(input);
     for i:=1 to 30 do
         for j:=1 to 30 do
             oo[i][j]:=chr(ord('Z')+1);
     re:=oo;  rm:=30;  rn:=30;
     att(1);
     if comp(re,oo,rm,rn,30,30)=0 then writeln('Impossible')
     else
     begin
          for i:=1 to rm do
          begin
               for j:=1 to rn do write(re[i][j]);
               writeln;
          end;
     end;
end.