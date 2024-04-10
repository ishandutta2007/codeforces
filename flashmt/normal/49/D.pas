uses math;
type ar=array[0..1111] of longint;
var n,i,re:longint;
    a,b:ar;
    c:char;

function check(a:ar;z:longint):longint;
var re,i,kt:longint;
begin
     re:=0;
     for i:=1 to n do b[i]:=i and 1 xor z;
     kt:=2;
     while kt=2 do
     begin
          kt:=0;
          for i:=1 to n do
              if a[i]<>b[i] then
              begin
                   kt:=1;
                   if (i>1) and (a[i-1]=a[i]) then
                   begin
                        a[i]:=1-a[i];
                        kt:=2;
                        break;
                   end;
                   if (i<n) and (a[i+1]=a[i]) then
                   begin
                        a[i]:=1-a[i];
                        kt:=2;
                        break;
                   end;
              end;
          if kt=2 then re:=re+1;
     end;
     if kt=1 then re:=10000;
     check:=re;
end;

begin
     readln(n);
     for i:=1 to n do
     begin
          read(c);
          a[i]:=ord(c)-48;
     end;
     re:=min(check(a,0),check(a,1));
     if re=10000 then writeln(-1)
     else writeln(re);
end.