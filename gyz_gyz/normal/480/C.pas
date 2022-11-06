const mx:int64=1000000007;
var
  f:array[0..1,0..5000]of int64;
  n,a,b,k,i,j,x,y:longint;
begin
  readln(n,a,b,k);
  if a>b then begin
    for i:=a to n do f[0,i]:=1;
    for i:=1 to k do begin
      x:=i and 1;
      for j:=b+1 to n do begin
        y:=(j-b-1) shr 1;
        f[x,j]:=(f[x,j-1]+f[1-x,n]-f[1-x,j]+f[1-x,j-1]-f[1-x,j-y-1]+mx+mx) mod mx;
      end;
    end;
    writeln(f[x,n]);
  end else begin
    for i:=a to b-1 do f[0,i]:=1;
    for i:=1 to k do begin
      x:=i and 1;
      for j:=1 to b-1 do begin
        y:=(b-j-1) shr 1;
        f[x,j]:=(f[x,j-1]+f[1-x,j+y]-f[1-x,j]+f[1-x,j-1]+mx) mod mx;
      end;
    end;
    writeln(f[x,b-1]);
  end;
end.