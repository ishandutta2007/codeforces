var s:ansistring;
    n,i,x,j,z:longint;
    a:array[1..55] of longint;
    f:array[0..1,0..10] of int64;
    d:array[1..55,0..9,0..9] of boolean;
    re:int64;

function check:boolean;
var i:longint;
begin
     for i:=2 to n do
         if not d[i,a[i-1],a[i]] then
         begin
              check:=false; exit;
         end;
     check:=true;
end;

begin
     readln(s);
     n:=length(s);
     for i:=1 to n do a[i]:=ord(s[i])-48;
     fillchar(f,sizeof(f),0);
     for i:=0 to 9 do f[1,i]:=1;
     z:=1;
     fillchar(d,sizeof(d),false);
     for i:=2 to n do
     begin
       z:=i and 1;
       fillchar(f[z],sizeof(f[z]),0);
       for j:=0 to 9 do
       begin
            x:=j+a[i];
            inc(f[z,x div 2],f[1-z,j]);
            d[i,j,x div 2]:=true;
            if odd(x) then
            begin
                 inc(f[z,x div 2+1],f[1-z,j]);
                 d[i,j,x div 2+1]:=true;
            end;
       end;
     end;
     re:=0;
     for i:=0 to 9 do re:=re+f[z,i];
     if check then dec(re);
     writeln(re);
end.