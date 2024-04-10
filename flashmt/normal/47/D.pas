const fi='';
var i,n,m,j,t,re:longint;
    a:array[0..10] of string;
    b:array[1..10] of longint;
    d:array[1..35] of longint;
    e:array[1..5] of longint;
    c:char;

function work:boolean;
var i,j,x:longint;
begin
     for i:=1 to n do d[i]:=49-ord(a[1,i]);
     for i:=1 to b[1] do d[e[i]]:=1-d[e[i]];
     work:=false;
     for i:=2 to m do
     begin
          x:=0;
          for j:=1 to n do
              if ord(a[i,j])-48=d[j] then x:=x+1;
          if x<>b[i] then exit;
     end;
     work:=true;
end;

procedure att(x,y:longint);
var i:longint;
begin
     if x>b[1] then
     begin
          if work then inc(re);
          exit;
     end;
     for i:=y to n+x-b[1] do
     begin
          e[x]:=i;
          att(x+1,i+1);
     end;
end;

begin
     assign(input,fi); reset(input);
     fillchar(d,sizeof(d),0);
     readln(n,m);
     for i:=1 to m do
     begin
          a[i]:='';
          for j:=1 to n do
          begin
               read(c);
               a[i]:=a[i]+c;
          end;
          readln(b[i]);
     end;
     for i:=1 to m-1 do
      for j:=i+1 to m do
       if b[i]>b[j] then
       begin
            a[0]:=a[i]; a[i]:=a[j]; a[j]:=a[0];
            t:=b[i]; b[i]:=b[j]; b[j]:=t;
       end;
     re:=0;
     att(1,1);
     writeln(re);
     close(Input);
end.