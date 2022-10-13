var s:string;
    a:array[1..55] of string;
    re,i,x,y,b,c,t,j,n:longint;
    ch:char;

begin
     re:=-1000000000;
     readln(n);
     for i:=1 to n do
     begin
          a[i]:='';
          while true do
          begin
               read(ch);
               if ch=' ' then break;
               a[i]:=a[i]+ch;
          end;
          read(b,c);
          x:=b*100-c*50;
          for j:=1 to 5 do
          begin
               read(y);
               x:=x+y;
          end;
          if x>re then
          begin
               re:=x; t:=i;
          end;
          readln;
     end;
     writeln(a[t]);
end.