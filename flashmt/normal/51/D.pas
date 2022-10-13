const fi='';
var n,i,zr:longint;
    a:array[1..100100] of longint;

function chk(l,r:longint):boolean;
var i:longint;
begin
     chk:=true;
     for i:=l+2 to r do
         if a[i-1]*a[i-1]<>a[i]*a[i-2] then
         begin
              chk:=false; exit;
         end;
end;

function chk1:boolean;
var i,j:longint;
begin
     chk1:=true;
     for i:=3 to n do
         if a[i-1]*a[2]<>a[1]*a[i] then break;
     if i=n then exit;
     if a[i-1]*a[2]<>a[1]*a[i+1] then
     begin
          chk1:=false; exit;
     end;
     for j:=i+2 to n do
         if a[j-1]*a[2]<>a[1]*a[j] then
         begin
              chk1:=false; break;
         end;
end;

begin
     assign(input,fi); reset(input);
     zr:=0;
     read(n);
     for i:=1 to n do
     begin
          read(a[i]);
          if a[i]=0 then zr:=zr+1;
     end;
     close(input);
     if zr>0 then
     begin
          if (zr=n) or ((zr=n-1) and (a[1]<>0)) then
          begin
               writeln(0); halt;
          end
          else
          begin
               if (zr+1=n) or ((zr+2=n) and (a[1]<>0)) then
               begin
                    writeln(1); halt;
               end;
          end;
          if zr>1 then
          begin
               writeln(2); halt;
          end;
     end;
     if chk(1,n) then writeln(0)
     else
     begin
          if chk1 then writeln(1)
          else
          begin
               if chk(2,n) then writeln(1)
               else
               begin
                    if chk(3,n) and (a[3]*a[3]=a[4]*a[1]) then writeln(1)
                    else writeln(2);
               end;
          end;
     end;
end.