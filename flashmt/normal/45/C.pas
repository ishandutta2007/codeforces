const fi='';
var n,i,nh,re,t,s,u,uu:longint;
    b:array[1..200010] of boolean;
    rx,ry,a,l,r,v,h,p:array[0..200020] of longint;
    c:char;

procedure add(x:longint);
var cha,con:longint;
begin
     if p[x]=0 then
     begin
          inc(nh); con:=nh;
     end
     else con:=p[x];
     cha:=con shr 1;
     while (cha>0) and ((v[x]<v[h[cha]]) or ((v[x]=v[h[cha]]) and (x<h[cha]))) do
     begin
          h[con]:=h[cha];
          p[h[con]]:=con;
          con:=cha; cha:=con shr 1;
     end;
     h[con]:=x; p[x]:=con;
end;

function pop:longint;
var x,cha,con,t,u:longint;
begin
     pop:=h[1];
     x:=h[nh]; dec(nh);
     cha:=1; con:=2;
     while con<=nh do
     begin
          t:=h[con]; u:=h[con+1];
          if (con<nh) and ((v[u]<v[t]) or ((v[u]=v[t]) and (u<t))) then inc(con);
          if (v[x]<v[h[con]]) or ((v[x]=v[h[con]]) and (x<h[con])) then break;
          h[cha]:=h[con];
          p[h[cha]]:=cha;
          cha:=con; con:=cha shl 1;
     end;
     h[cha]:=x; p[x]:=cha;
end;


function check(x:longint):boolean;
begin
     check:=(x>0) and (x<=n);
end;

begin
     assign(input,fi); reset(input);
     readln(n);
     for i:=1 to n do
     begin
          read(c);
          b[i]:=(c='B');
     end;
     for i:=1 to n do
     begin
          read(a[i]);
          r[i]:=i+1; l[i]:=i-1;
     end;
     nh:=0;
     fillchar(p,sizeof(p),0);
     for i:=1 to n-1 do
         if b[i] xor b[i+1] then
         begin
              v[i]:=abs(a[i]-a[i+1]);
              add(i);
         end;
     re:=0;
     for i:=1 to n do
     begin
          if nh<=0 then break;
          inc(re);
          t:=pop; u:=r[t]; uu:=r[u]; s:=l[t];
          rx[re]:=t; ry[re]:=u;
          r[s]:=uu; l[uu]:=s;
          if check(u) and (p[u]>0) then
          begin
               v[u]:=-1;
               add(u); t:=pop; p[u]:=0;
          end;
          if check(s) and (p[s]>0) then
          begin
               v[s]:=-1;
               add(s); t:=pop; p[s]:=0;
          end;
          if check(s) and check(uu) and (b[s] xor b[uu]) then
          begin
               v[s]:=abs(a[uu]-a[s]);
               add(s);
          end;
     end;
     writeln(re);
     for i:=1 to re do writeln(rx[i],' ',ry[i]);
     close(input);
end.