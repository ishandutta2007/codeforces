var f:array[0..20,-1..10,1..4,0..1] of int64;
    n,t:longint;
    re:int64;

procedure dp;
var i,j,p,q:longint;
begin
     for i:=1 to 4 do f[2,0,i,0]:=i-1;
     for i:=3 to n do
       for j:=0 to t do
         for p:=1 to 4 do
           for q:=1 to 4 do
             if p<>q then
             begin
                  if p>q then
                  begin
                       inc(f[i,j,p,0],f[i-1,j,q,0]);
                       inc(f[i,j,p,0],f[i-1,j,q,1]);
                  end
                  else
                  begin
                       inc(f[i,j,p,1],f[i-1,j,q,1]);
                       inc(f[i,j,p,1],f[i-1,j-1,q,0]);
                  end;
             end;
     for p:=1 to 4 do
         re:=re+f[n,t,p,1];
end;

begin
     read(n,t);
     dp;
     writeln(re);
end.