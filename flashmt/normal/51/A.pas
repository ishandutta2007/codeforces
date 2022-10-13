const fi='';
var n,i,j,re,k,u,p:longint;
    d,e:array[1..1111] of longint;
    a:array[1..1111,0..3] of longint;
    x,y:char;

function rot(x,y,z:longint):boolean;
var i:longint;
begin
     rot:=false;
     for i:=0 to 3 do
         if a[x,i]<>a[y,(i+z) mod 4] then exit;
     rot:=true;
end;

begin
     assign(input,fi); reset(input);
     readln(n);
     fillchar(e,sizeof(e),0);
     for i:=1 to n do d[i]:=i;
     for i:=1 to n do
     begin
          readln(x,y);
          a[i,0]:=ord(x)-48;
          a[i,1]:=ord(y)-48;
          readln(x,y);
          a[i,3]:=ord(x)-48;
          a[i,2]:=ord(y)-48;
          if i=n then break;
          readln(x,y);
     end;
     for i:=1 to n-1 do
       for j:=i+1 to n do
         if d[i]<>d[j] then
          for k:=0 to 3 do
            if rot(i,j,k) then
            begin
                 u:=d[i];
                 for p:=1 to n do
                     if d[p]=u then d[p]:=d[j];
                 break;
            end;
     re:=0;
     for i:=1 to n do
         if e[d[i]]=0 then
         begin
              e[d[i]]:=1; inc(re);
         end;
     writeln(re);
     close(input);
end.