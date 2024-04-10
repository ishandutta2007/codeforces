program roadDestroying;

const
  maxN = 5000;

var 
  n, m: longint;
  va, vb: array [1 .. maxN] of longint;
  gc: array [1 .. maxN] of longint;
  gv: array [1 .. maxN] of array of longint;
  d: array [1 .. maxN, 1 .. maxN] of longint;
  q: array [1 .. maxN] of longint;
  qb, qe: longint;
  s1, t1, l1, s2, l2, t2: longint;
  ans: longint = -1;

procedure ReadData;
var i: longint;
begin
  read(n, m);
  for i := 1 to m do read(va[i], vb[i]);
  read(s1, t1, l1);
  read(s2, t2, l2);
end;

procedure InitAll;
var i: longint;
begin
  for i := 1 to m do 
  begin
    inc(gc[va[i]]);
    inc(gc[vb[i]]);
  end;
  for i := 1 to n do 
  begin
    SetLength(gv[i], gc[i] + 1);
    gc[i] := 0;
  end;
  for i := 1 to m do
  begin
    gv[va[i], gc[va[i]]] := vb[i];
    inc(gc[va[i]]);
    gv[vb[i], gc[vb[i]]] := va[i];
    inc(gc[vb[i]]);
  end;
end;

procedure CalcDistances;
var i, j, cur, nxt: longint;
begin
  for i := 1 to n do
  begin 
    qb := 0; qe := 0;
    for j := 1 to n do d[i, j] := -1;
    d[i, i] := 0;
    inc(qb); q[qb] := i; 
    while qb <> qe do
    begin
      inc(qe);
      cur := q[qe];
      for j := 0 to gc[cur] - 1 do
      begin
        nxt := gv[cur, j];
        if d[i, nxt] >= 0 then continue;
        d[i, nxt] := d[i, cur] + 1;
        inc(qb); q[qb] := nxt;
      end;
    end;
  end;
end;
   
procedure UpdateAns(newAns: longint);
begin
  if newAns > ans then ans := newAns;
end;

procedure RunSolution;
var i, j: longint;
begin
  CalcDistances;
  if (d[s1, t1] <= l1) and (d[s2, t2] <= l2) 
     then UpdateAns(m - d[s1, t1] - d[s2, t2]); 
  for i := 1 to n do
    for j := 1 to n do
    begin  
      if (d[s1, i] + d[i, j] + d[j, t1] <= l1) and (d[s2, i] + d[i, j] + d[j, t2] <= l2) 
         then UpdateAns(m - d[s1, i] - d[j, t1] - d[s2, i] - d[j, t2] - d[i, j]);
      if (d[s1, i] + d[i, j] + d[j, t1] <= l1) and (d[t2, i] + d[i, j] + d[j, s2] <= l2)
         then UpdateAns(m - d[s1, i] - d[j, t1] - d[t2, i] - d[j, s2] - d[i, j]);
    end;
end;

procedure WriteData;
begin
  write(ans);
end;

begin
  ReadData;
  InitAll;
  RunSolution;
  WriteData;
end.