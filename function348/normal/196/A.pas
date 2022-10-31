var
        s:ansistring;
        n,i,x:longint;
        a:array[0..100001,-1..25]of boolean;
        b:array[0..100000]of longint;
begin
        readln(s);n:=length(s);
        for i:=n downto 1 do
        begin
                x:=ord(s[i])-97;
                b[i]:=x;
                a[i]:=a[i+1];
                a[i,x]:=true;
        end;
        x:=25;
        for i:=1 to n do
        begin
                while not a[i,x]and(x>=0) do dec(x);
                if x<0 then break;
                if b[i]=x then write(chr(x+97));
        end;
        writeln;
end.