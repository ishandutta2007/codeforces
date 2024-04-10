program Project705Cfailedattempt2;
uses math;
type app = record
     num, read2, read3: integer;
     end;
var n, q, x, i, j, tmpA, typei, unread, t, tmp: integer;
    A: array[1..300000] of int64;
    B: array[1..300000] of app;
begin
  tmp := 0;
  tmpA := 0;
  unread := 0;
  readln(n, q);
  for i := 1 to q do
  begin
    read(typei);
    if typei = 1 then
    begin
      readln(x);
      inc(tmpA);
      A[tmpA] := x;
      inc(B[x].num);
      inc(unread);
    end
    else if typei = 2 then
    begin
      readln(x);
      dec(unread, B[x].num - max(B[x].read2, B[x].read3));
      //writeln('Decreased <unread> by ', B[x].num - max(B[x].read2, B[x].read3));
      B[x].read2 := B[x].num;
      //writeln('B[', x, '].read2 is now ', B[x].num);
    end
    else
    begin
      readln(t);
      //writeln('Tmp is currently ', tmp);
      if tmp < t then
      begin
        for j := tmp + 1 to t do
        begin
          inc(B[A[j]].read3);
          if B[A[j]].read3 > B[A[j]].read2 then
          begin
            //writeln('B[', A[j], '].read3 is ', B[A[j]].read3, ' and larger than B[', A[j], '].read2 (', B[A[j]].read2, ')');
            dec(unread);
            //writeln('Decreased <unread> at B[', A[j], ']');
          end
        end;
      tmp := t;
      end;
    end;
    writeln(unread);
  end;
  //readln; readln;
end.