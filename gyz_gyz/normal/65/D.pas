const
  mx=100;
  u:array[1..4]of string=('Gryffindor','Hufflepuff','Ravenclaw','Slytherin');
var
  a:array[0..mx,0..mx,0..mx,0..mx]of boolean;
  b:array[1..10000]of longint;
  c,ans:array[1..4]of boolean;
  n,i,j,k,l,s,mi:longint;
  ch:char;
procedure shiagain;
var
  d:array[1..4]of longint;
  w,mi,tp,i,j,k:longint;
begin
  randomize;
  for w:=1 to 1000 do begin
    fillchar(c,sizeof(c),0);
    for i:=1 to n do
      if b[i]>0 then inc(c[b[i]]);
    fillchar(d,sizeof(d),0);
    for i:=1 to n do begin
      if b[i]=0 then begin
        mi:=maxlongint;
        for j:=1 to 4 do
          if d[j]<mi then mi:=d[j];
        tp:=0;
        while tp=0 do begin
          for j:=1 to 4 do
            if (d[j]=mi)and(random(2)=1) then begin
              tp:=j;
            end;
        end;
        inc(c[tp]);inc(d[tp]);
      end else inc(d[b[i]]);
    end;
    mi:=maxlongint;
    for j:=1 to 4 do
      if d[j]<mi then mi:=d[j];
    for i:=1 to 4 do
      if d[i]=mi then ans[i]:=true;
  end;
  for i:=1 to 4 do
    if ans[i] then writeln(u[i]);
  writeln;
end;
procedure shi;
var
  c,d:array[1..4]of longint;
  w,mi,rw,tp,i,j,k:longint;
begin
  for w:=1 to 4 do begin
    fillchar(c,sizeof(c),0);
    for i:=1 to n do
      if b[i]>0 then inc(c[b[i]]);
    fillchar(d,sizeof(d),0);
    for i:=1 to n do begin
      if b[i]=0 then begin
        mi:=maxlongint;
        for j:=1 to 4 do
          if d[j]<mi then mi:=d[j];
        rw:=maxlongint;tp:=0;
        for j:=1 to 4 do
          if (j<>w)and(c[j]<rw)and(d[j]=mi) then begin
            tp:=j;rw:=c[j];
          end;
        if tp=0 then tp:=w;
        inc(c[tp]);inc(d[tp]);
      end else inc(d[b[i]]);
    end;
    mi:=maxlongint;
    for j:=1 to 4 do
      if d[j]<mi then mi:=d[j];
    if d[w]=mi then ans[w]:=true;
  end;
  shiagain;
end;
begin
  readln(n);
    for i:=1 to n do begin
      read(ch);
      if ch='G' then b[i]:=1;
      if ch='H' then b[i]:=2;
      if ch='R' then b[i]:=3;
      if ch='S' then b[i]:=4;
      if ch='?' then b[i]:=0;
    end;
    readln;
    if n>mx then begin
      shi;halt;
    end;
    fillchar(a,sizeof(a),0);
    fillchar(c,sizeof(c),0);
    a[0,0,0,0]:=true;
    for i:=0 to n-1 do
      for j:=0 to i do
        for k:=0 to i-j do
          for l:=0 to i-j-k do
            if a[i,j,k,l] then begin
              s:=i-j-k-l;
              if b[i+1]=1 then a[i+1,j+1,k,l]:=true;
              if b[i+1]=2 then a[i+1,j,k+1,l]:=true;
              if b[i+1]=3 then a[i+1,j,k,l+1]:=true;
              if b[i+1]=4 then a[i+1,j,k,l]:=true;
              if b[i+1]=0 then begin
                mi:=maxlongint;
                if j<mi then mi:=j;
                if k<mi then mi:=k;
                if l<mi then mi:=l;
                if s<mi then mi:=s;
                if j=mi then a[i+1,j+1,k,l]:=true;
                if k=mi then a[i+1,j,k+1,l]:=true;
                if l=mi then a[i+1,j,k,l+1]:=true;
                if s=mi then a[i+1,j,k,l]:=true;
              end;
            end;
    mi:=maxlongint;
    for i:=0 to n do
      for j:=0 to n-i do
        for k:=0 to n-i-j do
          if a[n,i,j,k] then begin
            l:=n-i-j-k;
            mi:=maxlongint;
            if i<mi then mi:=i;
            if j<mi then mi:=j;
            if k<mi then mi:=k;
            if l<mi then mi:=l;
            if i=mi then c[1]:=true;
            if j=mi then c[2]:=true;
            if k=mi then c[3]:=true;
            if l=mi then c[4]:=true;
          end;
    if c[1] then writeln('Gryffindor');
    if c[2] then writeln('Hufflepuff');
    if c[3] then writeln('Ravenclaw');
    if c[4] then writeln('Slytherin');
end.