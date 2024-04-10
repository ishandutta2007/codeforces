const dx:array[1..8] of longint=(-2,-1,1,2,2,1,-1,-2);
      dy:array[1..8] of longint=(1,2,2,1,-1,-2,-2,-1);
var a,b,c,d,re,i,j,k:longint;
    ch:char;
    f:array[1..8,1..8] of boolean;

begin
     read(ch);
     a:=ord(ch)-96;
     readln(b);
     read(ch);
     c:=ord(ch)-96;
     readln(d);
     fillchar(f,sizeof(f),false);
     f[c,d]:=true;
     re:=0;
     for j:=1 to 8 do f[a,j]:=true;
     for i:=1 to 8 do f[i,b]:=true;


     for k:=1 to 8 do
     begin
          i:=c+dx[k]; j:=d+dy[k];
          if (i>0) and (i<9) and (j>0) and (j<9) then f[i,j]:=true;
          i:=a+dx[k]; j:=b+dy[k];
          if (i>0) and (i<9) and (j>0) and (j<9) then f[i,j]:=true;
     end;
     for i:=1 to 8 do
      for j:=1 to 8 do
       if not f[i,j] then inc(re);
     writeln(re);
end.