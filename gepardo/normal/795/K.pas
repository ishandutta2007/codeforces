{$mode objfpc}{$h+}

var
  n: integer;
  i: integer;
  s: string;
  res: string;
  curChar: char;
  curKnt: integer;
  
const
  gl = ['a', 'e', 'i', 'o', 'u', 'y'];
  exGl = ['e', 'o'];
  
procedure work;
var
  i: integer;
begin
  if curChar in gl then begin
    if (curChar in exGl) and (curKnt = 2) then begin
      write(curChar, curChar);
    end else begin
      write(curChar);
    end;
  end else begin
    for i := 1 to curKnt do begin
      write(curChar);
    end;
  end;
end;
  
begin
  readln(n);
  readln(s);
  curChar := s[1];
  curKnt := 1;
  for i := 2 to n do begin
    if s[i] = s[i-1] then begin
      inc(curKnt);
    end else begin
      work;
      curChar := s[i];
      curKnt := 1;
    end;
  end;
  work;
end.