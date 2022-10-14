const fi='';
var m,n,i,j:longint;
    c:char;
    re:int64;
    a:array[1..1111,1..1111] of boolean;
    row,col:array[1..1111] of longint;

begin
     assign(input,fi); reset(input);
     readln(m,n);
     fillchar(row,sizeof(row),0);
     fillchar(col,sizeof(col),0);
     for i:=1 to m do
     begin
      for j:=1 to n do
      begin
           read(c);
           a[i,j]:=(c='*');
           if a[i,j] then row[i]:=row[i]+1;
      end;
      readln;
     end;
     re:=0;
     for i:=1 to m do
      for j:=1 to n do
       if a[i,j] then
       begin
            re:=re+col[j]*(row[i]-1);
            col[j]:=col[j]+1;
       end;
     fillchar(col,sizeof(col),0);
     for i:=m downto 1 do
      for j:=1 to n do
       if a[i,j] then
       begin
            re:=re+col[j]*(row[i]-1);
            col[j]:=col[j]+1;
       end;
     writeln(re);
     close(input);
end.