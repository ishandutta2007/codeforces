const dx:array[1..4] of longint=(-1,0,1,0);
      dy:array[1..4] of longint=(0,1,0,-1);
var m,n,i,j,x:longint;
    a:array[0..101,0..101] of longint;

function check(x,y,v:longint):boolean;
var i,j,k:longint;
begin
     for k:=1 to 4 do
     begin
          i:=x+dx[k]; j:=y+dy[k];
          if a[i,j]=v-1 then
          begin
               check:=false; exit;
          end;
     end;
     check:=true;
end;

procedure att(x:longint);
var i,j,k,ii,jj:longint;
begin
     if x>m*n then
     begin
          for i:=1 to m do
          begin
               for j:=1 to n do write(a[i,j],' ');
               writeln;
          end;
          halt;
     end;
     for i:=1 to m do
       for j:=1 to n do
         if (a[i,j]<0) and check(i,j,x) then
         begin
              a[i,j]:=x;
              att(x+1);
              a[i,j]:=-1;
         end;
end;

begin
     read(m,n);
     for i:=0 to m+1 do
      for j:=0 to n+1 do
       a[i,j]:=-1;
     att(1);
     writeln(-1);
end.