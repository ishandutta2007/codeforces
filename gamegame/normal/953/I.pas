var cnt:array[0..1440]of longint;
    i,sol,n,k,ans,prv:longint;
    s:string;

begin
    readln(n);
    for i:=0 to 1439 do cnt[i]:=0;
    for i:=1 to n do
        begin
            readln(s);
            k:=(Ord(s[1])-48)*600+(Ord(s[2])-48)*60+(Ord(s[4])-48)*10+(Ord(s[5])-48);
            cnt[k]:=cnt[k]+1;
        end;
        
    for i:=0 to 1439 do
        begin
            if cnt[i]<>0 then prv:=i
        end;
    prv:=prv-1440;
    ans:=0;
    for i:=0 to 1439 do
        begin
            if cnt[i]<>0 then 
                begin
                    if ans<i-prv then ans:=i-prv-1;
                    prv:=i;
                end
        end;
    write(ans div 600);
    write(ans mod 600 div 60);
    write(':');
    write(ans mod 60 div 10);
    write(ans mod 10);
end.