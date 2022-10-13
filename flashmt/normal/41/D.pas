uses math;
const fi='';
var m,n,k,i,j,p,x,y,re,xx:longint; c:char;
    a:array[1..111,1..111] of longint;
    f,tr:array[1..111,1..111,0..10] of longint;
    d:array[1..111] of longint;

begin
     assign(input,fi); reset(input);
     readln(m,n,k);
     inc(k);
     for i:=1 to m do
     begin
          for j:=1 to n do
          begin
               read(c);
               a[i][j]:=ord(c)-48;
          end;
          readln;
     end;
     for i:=1 to m do
      for j:=1 to n do
       for p:=0 to k-1 do
        f[i][j][p]:=-1;
     for j:=1 to n do f[m,j,a[m][j] mod k]:=a[m][j];
     for i:=m-1 downto 1 do
     begin
          for j:=1 to n-1 do
            for p:=0 to k-1 do
               if f[i+1][j+1][p]>=0 then
               begin
                    f[i][j][(p+a[i][j]) mod k]:=f[i+1][j+1][p]+a[i][j];
                    tr[i][j][(p+a[i][j]) mod k]:=1;
               end;
          for j:=2 to n do
            for p:=0 to k-1 do
              if f[i+1][j-1][p]>=0 then
              begin
                   x:=f[i+1][j-1][p]+a[i][j];
                   y:=(p+a[i][j]) mod k;
                   if f[i][j][y]<x then
                   begin
                        f[i][j][y]:=x; tr[i][j][y]:=-1;
                   end;
              end;
     end;
     re:=-1; y:=0;
     for j:=1 to n do
         if f[1][j][0]>re then
         begin
              re:=f[1][j][0]; y:=j;
         end;
     if y=0 then writeln(-1)
     else
     begin
          writeln(re);
          d[1]:=y; x:=0;
          for i:=2 to m do
          begin
               xx:=x;
               x:=(x-a[i-1][y]) mod k;
               if x<0 then x:=x+k;
               y:=y+tr[i-1][y][xx];
               d[i]:=y;
          end;
          writeln(d[m]);
          for i:=m-1 downto 1 do
              if d[i]>d[i+1] then write('R') else write('L');
          writeln;
     end;
     close(input);
end.