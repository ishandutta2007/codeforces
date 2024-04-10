uses math;
var n,i,s,m,mm,re,r,rr:longint;
    a:array[1..200,1..200] of boolean;
    b:array[1..200,0..1] of longint;

procedure visit(x,y:longint;var m,r:longint);
var i,t,mm:longint;
begin
     m:=0; mm:=0;
     for i:=1 to n do
         if (i<>y) and a[x,i] then
         begin
              visit(i,x,t,r);
              if t+1>m then
              begin
                   mm:=m; m:=t+1;
              end
              else
              begin
                   if t+1>mm then mm:=t+1;
              end;
         end;
     r:=max(r,m+mm);
end;

begin
     read(n);
     for i:=1 to n-1 do
     begin
          read(b[i,0],b[i,1]);
          a[b[i,0],b[i,1]]:=true;
          a[b[i,1],b[i,0]]:=true;
     end;
     for i:=1 to n-1 do
     begin
          a[b[i,0],b[i,1]]:=false;
          a[b[i,1],b[i,0]]:=false;
          r:=0; rr:=0;
          visit(b[i,0],0,m,r);
          visit(b[i,1],0,m,rr);
          re:=max(re,r*rr);
          a[b[i,0],b[i,1]]:=true;
          a[b[i,1],b[i,0]]:=true;
     end;
     writeln(re);
end.