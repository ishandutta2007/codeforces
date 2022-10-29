var n,k,a,b,cnt,i: longint;
    chk:boolean; ans:ansistring='';
begin
    read(n,k,a,b);
    if a<b then begin a:=a+b; b:=a-b; a:=a-b; chk:=true; end;
    cnt:=(a-1)div k; if b<cnt then begin write('NO'); exit; end;
    while cnt>=0 do begin if b>cnt then
    repeat ans:=ans+'B'; dec(b); until b<=k*cnt;
    repeat ans:=ans+'G'; dec(a); until a<=k*cnt; dec(cnt); end;
    if chk then for i:=1to n do if ans[i]='B'then ans[i]:='G'else ans[i]:='B';
    write(ans);
end.