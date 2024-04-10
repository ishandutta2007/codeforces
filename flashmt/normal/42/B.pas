const dx:array[1..8] of longint=(-1,-1,0,1,1,1,0,-1);
      dy:array[1..8] of longint=(0,1,1,1,0,-1,-1,-1);
var a,b,aa,bb,c,cc,d,dd,i,j:longint;
    ch:char;
    e:array[0..9,0..9] of longint;

function check:boolean;
var i,x,y:longint;
begin
     check:=false;
     if e[d,dd]=0 then exit;
     for i:=1 to 8 do
     begin
          x:=d+dx[i]; y:=dd+dy[i];
          if (x>0) and (y>0) and (x<9) and (y<9) and (e[x,y]<=0) then exit;
     end;
     check:=true;
end;

begin
     read(ch); a:=ord(ch)-96; read(aa);
     read(ch,ch); b:=ord(ch)-96; read(bb);
     read(ch,ch); c:=ord(ch)-96; read(cc);
     read(ch,ch); d:=ord(ch)-96; read(dd);
     e[a,aa]:=-1; e[b,bb]:=-1; e[c,cc]:=-1;
     for i:=a-1 downto 1 do
         if e[i,aa]<0 then break else e[i,aa]:=1;
     for i:=a+1 to 8 do
         if e[i,aa]<0 then break else e[i,aa]:=1;
     for i:=b-1 downto 1 do
         if e[i,bb]<0 then break else e[i,bb]:=1;
     for i:=b+1 to 8 do
         if e[i,bb]<0 then break else e[i,bb]:=1;
     for i:=aa-1 downto 1 do
         if e[a,i]<0 then break else e[a,i]:=1;
     for i:=aa+1 to 8 do
         if e[a,i]<0 then break else e[a,i]:=1;
     for i:=bb-1 downto 1 do
         if e[b,i]<0 then break else e[b,i]:=1;
     for i:=bb+1 to 8 do
         if e[b,i]<0 then break else e[b,i]:=1;
     if (a=b) or (aa=bb) then
     begin
          e[a,aa]:=1; e[b,bb]:=1;
     end;
     for i:=1 to 8 do e[c+dx[i],cc+dy[i]]:=1;
     if check then writeln('CHECKMATE')
     else writeln('OTHER');
end.