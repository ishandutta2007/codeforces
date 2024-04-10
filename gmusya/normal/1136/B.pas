var n,k,luki,hodi,broski: longint;

begin
  readln (n,k);
  broski:=n+1;
  hodi:=min(k-1+n-1,n-k+n-1);
  luki:=n;
  writeln (broski+hodi+luki);
end.