const fi='';
      ep=0.0000001;
var n,i,m:longint;
    a:array[1..200020] of longint;
    b:array[1..4] of longint;
    lo,hi,mi,re:longint;
    t:boolean;

procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
     i:=l; j:=r; x:=a[(i+j) div 2];
     repeat
           while a[i]<x do i:=i+1;
           while a[j]>x do j:=j-1;
           if i<=j then
           begin
                y:=a[i]; a[i]:=a[j]; a[j]:=y;
                i:=i+1; j:=j-1;
           end;
     until i>j;
     if i<r then sort(i,r);
     if l<j then sort(l,j);
end;

function check(x:longint):boolean;
var i:longint;
begin
     check:=true;
     m:=1; b[1]:=a[1]+x;
     for i:=1 to n do
         if abs(a[i]-b[m])>x then
         begin
              inc(m);
              if m=4 then
              begin
                   check:=false; exit;
              end;
              b[m]:=a[i]+x;
         end;
     if m<3 then
       for i:=m+1 to 3 do b[i]:=b[i-1];
end;

begin
     assign(input,fi); reset(input);
     read(n);
     for i:=1 to n do
     begin
          read(a[i]);
          a[i]:=a[i]*2;
     end;
     sort(1,n);
     lo:=0; hi:=2000000000;
     while hi>=lo do
     begin
          mi:=(lo+hi) div 2;
          if check(mi) then
          begin
               re:=mi; hi:=mi-1;
          end
          else lo:=mi+1;
     end;
     t:=check(re);
     writeln(re*0.5:0:6);
     for i:=1 to 3 do write(b[i]*0.5:0:6,' ');
     writeln;
     close(input);
end.