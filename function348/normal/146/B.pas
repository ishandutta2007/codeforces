var
        a,b:longint;
        s:string;
function check(a:longint):boolean;
var c,d:longint;
begin
        s:='';
        while a>0 do
        begin
                c:=a mod 10;
                if (c=4)or(c=7) then s:=chr(c+48)+s;
                a:=a div 10;
        end;
        val(s,d);
        if b=d then exit(true)
               else exit(false);
end;
begin
        readln(a,b);
        repeat
                inc(a);
        until check(a);
        writeln(a);
end.