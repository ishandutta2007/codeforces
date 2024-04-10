var s: ansistring;
        n, i, c, mn, k: longint;
        pf, dp, open: Array [0..1069420] of longint;

//You might ask: Why am I doing this in Pascal?
//Well, I want to go do something stupid for a little bit to clear my brain
//it's dumb but I'm also dumb
//so it kinda matches
begin
//cf Pascal is retarded
//so I have to do some stupid stuff
    c:=0;
    readln(n);
    readln(s);
    for i:=1 to n do
    begin
        if(s[i]='(') then open[i]:=1
        else open[i]:=0;
        pf[i]:=pf[i-1]+2*open[i]-1;
    end;
    for i:=1 to n do
        if(dp[i-1]<pf[i]) then dp[i]:=dp[i-1]
        else dp[i]:=pf[i];
    mn:=100000000;
    for i:=n downto 1 do
    begin    
        if(mn>pf[i]) then mn:=pf[i];
    	k:=open[i]*2-1;
    	if((pf[n]-k*2=0) and (dp[i-1]=0) and (mn-k*2=0)) then inc(c);
    end;
    writeln(c);
end.