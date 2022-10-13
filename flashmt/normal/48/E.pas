uses math;
const fi='';
var h,t,r,m,n,i,j,numm,hh,tt,cnt,sm,last,u,k,re:longint;
    a,b,aa,bb:array[1..222] of longint;
    q,st:array[1..160000,0..1] of longint;
    d,sl,low,num,l,dd:array[0..200,0..200] of longint;
    c:array[0..200,0..200,1..400] of longint;
    dr:boolean;
    fr,lose:array[0..200,0..200] of boolean;

procedure check(z:longint);
begin
     if (h=hh) and (t=tt) then dr:=true;
     if hh+tt=0 then
     begin
          writeln('Ivan');
          writeln(d[h,t]);
          halt;
     end;
     if hh+tt>r then
     begin
          lose[h,t]:=true;
          exit;
     end;
     if d[hh,tt]=0 then
     begin
          numm:=numm+1;
          q[numm,0]:=hh;
          q[numm,1]:=tt;
          d[hh,tt]:=d[h,t]+1;
     end;
     inc(sl[h,t]);
     c[h,t,sl[h,t]]:=z;
end;

procedure push(h,t:longint);
begin
     inc(last);
     st[last,0]:=h; st[last,1]:=t;
end;

procedure pop(var h,t:longint);
begin
     h:=st[last,0]; t:=st[last,1];
     dec(last);
end;

procedure visit(h,t:longint);
var u,i,hh,tt:longint;
begin
     cnt:=cnt+1; low[h,t]:=cnt; num[h,t]:=cnt;
     push(h,t);
     for i:=1 to sl[h,t] do
     begin
          u:=c[h,t,i];
          if u>0 then
          begin
               hh:=h-u+a[u]; tt:=t+b[u];
          end
          else
          begin
               hh:=h+aa[-u]; tt:=t+u+bb[-u];
          end;
          if not fr[hh,tt] then
          begin
               if num[hh,tt]>0 then low[h,t]:=min(low[h,t],num[hh,tt])
               else
               begin
                    visit(hh,tt);
                    low[h,t]:=min(low[h,t],low[hh,tt]);
               end;
          end;
     end;
     if low[h,t]=num[h,t] then
     begin
          inc(sm);
          repeat
                pop(hh,tt);
                if (hh<>h) or (tt<>t) then dr:=true;
                l[hh,tt]:=sm;
                fr[hh,tt]:=true;
          until (hh=h) and (tt=t);
     end;
end;

begin
     assign(input,fi); reset(input);
     read(h,t,r,m);
     for i:=1 to m do read(a[i],b[i]);
     read(n);
     for i:=1 to n do read(aa[i],bb[i]);
     close(input);
     dr:=false;
     fillchar(d,sizeof(d),0);
     fillchar(sl,sizeof(sl),0);
     fillchar(fr,sizeof(fr),false);
     fillchar(num,sizeof(num),0);
     fillchar(dd,sizeof(dd),0);
     fillchar(lose,sizeof(lose),false);
     d[h,t]:=1; q[1,0]:=h; q[1,1]:=t;  dd[h,t]:=1;
     numm:=1; re:=0; i:=1;
     cnt:=0; last:=0; sm:=0;
     repeat
           h:=q[i,0]; t:=q[i,1];
           for j:=1 to min(h,m) do
           begin
                hh:=h-j+a[j];
                tt:=t+b[j];
                check(j);
           end;
           for j:=1 to min(t,n) do
           begin
                hh:=h+aa[j];
                tt:=t-j+bb[j];
                check(-j);
           end;
           i:=i+1;
     until i>numm;
     for i:=1 to numm do
         if not fr[q[i,0],q[i,1]] then
            visit(q[i,0],q[i,1]);
     if dr then writeln('Draw')
     else
     begin
          for k:=1 to numm-1 do
          begin
               dr:=false;
               for j:=1 to numm do
               begin
                    h:=q[j,0]; t:=q[j,1];
                    for i:=1 to sl[h,t] do
                    begin
                         u:=c[h,t,i];
                         if u>0 then
                         begin
                              hh:=h-u+a[u]; tt:=t+b[u];
                         end
                         else
                         begin
                              hh:=h+aa[-u]; tt:=t+u+bb[-u];
                         end;
                         if dd[hh,tt]<dd[h,t]+1 then
                         begin
                              dd[hh,tt]:=dd[h,t]+1;
                              if lose[hh,tt] then
                                 re:=max(re,dd[hh,tt]);
                              dr:=true;
                         end;
                    end;
               end;
               if not dr then break;
          end;
          writeln('Zmey');
          writeln(re);
     end;
end.