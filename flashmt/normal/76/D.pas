uses math;
var a,b,x,y,ta,tb:qword;
    r:array[0..65] of qword;
    m,n,i:longint;
    aa,bb:array[0..65] of longint;

procedure att(i,mem:longint);
var p,q:longint;
begin
     if (x+y=a) and (x xor y=b) then
     begin
          writeln(x,' ',y);
          halt;
     end;
     if (x+y>a) or (i>max(m,n)) then exit;
     for p:=0 to 1 do
      for q:=0 to 1 do
       if ((p+q+mem) and 1=aa[i]) and (p xor q=bb[i]) then
       begin
            x:=x+r[i]*p; y:=y+r[i]*q;
            att(i+1,(p+q+mem) div 2);
            x:=x-r[i]*p; y:=y-r[i]*q;
       end;
end;

begin
     read(a,b); ta:=a; tb:=b;
     while ta>0 do
     begin
          aa[m]:=ta and 1;
          ta:=ta shr 1;
          m:=m+1;
     end;
     while tb>0 do
     begin
          bb[n]:=tb and 1;
          tb:=tb shr 1;
          n:=n+1;
     end;
     r[0]:=1;
     for i:=1 to 63 do r[i]:=r[i-1]*2;
     att(0,0);
     writeln(-1);
end.