const fi='';
      r='ard';
      rr:array[1..3] of longint=(7,4,4);
var s,ss:string;
    a,re,d:array[1..2222] of longint;
    b,c:array[1..3,1..2222] of longint;
    sl,cur:array[1..3] of longint;
    n,i,m,t:longint;

function calc(l,r:longint):longint;
var i,j,res,s:longint;
begin
     if l+1=r then
     begin
          calc:=1; exit;
     end;
     if l>=r then
     begin
          calc:=0; exit;
     end;
     i:=l; j:=d[i]; res:=0;
     while true do
     begin
          s:=calc(i+1,j-1)+ord(a[i]=3);
          if a[i]=1 then
          begin
               inc(m);
               re[m]:=s;
               s:=0;
          end;
          res:=res+s;
          if j=r then break;
          i:=j+1; j:=d[i];
     end;
     calc:=res;
end;

procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
     i:=l; j:=r; x:=re[(i+j) div 2];
     repeat
           while re[i]<x do i:=i+1;
           while re[j]>x do j:=j-1;
           if i<=j then
           begin
                y:=re[i]; re[i]:=re[j]; re[j]:=y;
                i:=i+1; j:=j-1;
           end;
     until i>j;
     if i<r then sort(i,r);
     if l<j then sort(l,j);
end;

begin
     assign(input,fi); reset(input);
     s:='';
     while not eof do
     begin
          readln(ss);
          s:=s+ss;
     end;
     n:=0;
     fillchar(sl,sizeof(sl),0);
     fillchar(cur,sizeof(cur),0);
     while s<>'' do
     begin
          inc(n);
          if s[2]<>'/' then
          begin
               a[n]:=pos(s[3],r);
               delete(s,1,rr[a[n]]);
               inc(sl[a[n]]);
               b[a[n],sl[a[n]]]:=n;
               inc(cur[a[n]]);
               c[a[n],cur[a[n]]]:=n;
          end
          else
          begin
               a[n]:=pos(s[4],r);
               delete(s,1,rr[a[n]]+1);
               d[c[a[n],cur[a[n]]]]:=n;
               dec(cur[a[n]]);
               a[n]:=-a[n];
          end;
     end;
     m:=0;
     t:=calc(1,n);
     sort(1,m);
     for i:=1 to m do write(re[i],' ');
     writeln;
     close(input);
end.