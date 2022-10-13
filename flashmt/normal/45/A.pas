const a:array[0..11] of string=('January','February','March','April','May','June','July','August','September','October','November','December');
var s:string;
    i,x:longint;
begin
     readln(s);
     for i:=0 to 11 do
        if s=a[i] then break;
     read(x);
     x:=(x+i) mod 12;
     writeln(a[x]);
end.