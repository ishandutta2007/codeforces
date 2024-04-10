uses math;
const fi='';
      maxn=200020;
var n,i,x,y,m,z:longint;
    a,b:array[1..maxn*5] of int64;
    oo,re:int64;

procedure add(nd,l,r,x,y,z:longint);
var mid:longint;
begin
     if (l=x) and (r=y) then
     begin
          a[nd]:=a[nd]+z;
          b[nd]:=b[nd]+z;
     end
     else
     begin
          mid:=(l+r) shr 1;
          if x<=mid then add(nd*2,l,mid,x,min(y,mid),z);
          if mid<y then add(nd*2+1,mid+1,r,max(x,mid+1),y,z);
          a[nd]:=min(a[nd*2],a[nd*2+1])+b[nd];
     end;
end;

function get(nd,l,r,x,y:longint):int64;
var t,u:int64; mid:longint;
begin
     if (l=x) and (r=y) then get:=a[nd]
     else
     begin
          t:=1000000000; t:=t*t; u:=t; mid:=(l+r) shr 1;
          if x<=mid then t:=get(nd*2,l,mid,x,min(y,mid));
          if mid<y then u:=get(nd*2+1,mid+1,r,max(x,mid+1),y);
          get:=min(t,u)+b[nd];
     end;
end;

begin
     assign(input,fi); reset(input);
     read(n);
     for i:=1 to n do
     begin
          read(x);
          add(1,1,n,i,i,x);
     end;
     read(m);
     for i:=1 to m do
     begin
          read(x,y);
          if not eoln then
          begin
               read(z);
               if x<=y then add(1,1,n,x+1,y+1,z)
               else
               begin
                    add(1,1,n,x+1,n,z);
                    add(1,1,n,1,y+1,z);
               end;
          end
          else
          begin
               if x<=y then re:=get(1,1,n,x+1,y+1)
               else re:=min(get(1,1,n,x+1,n),get(1,1,n,1,y+1));
               writeln(re);
          end;
     end;
     close(input);
end.