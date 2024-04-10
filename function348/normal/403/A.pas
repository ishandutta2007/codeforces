var
        ii,t,n,p,j,k,i:longint;
begin
        readln(t);
        for ii:=1 to t do
        begin
                readln(n,p);j:=1;k:=2;
                for i:=1 to 2*n+p do
                begin
                        writeln(j,' ',k);
                        inc(k);
                        if k=n+1 then
                        begin
                                inc(j);k:=j+1;
                        end;
                end;
        end;
end.