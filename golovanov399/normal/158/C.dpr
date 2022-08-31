program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

type
 TStack = record
  n: integer;
  a: array[1..1000] of string;
 end;

procedure init(var s: TStack);
begin
 fillchar(s, sizeof(s), 0);
end;

procedure push(var s: TStack; t: string);
begin
 inc(s.n);
 s.a[s.n] := t;
end;

function top(s: TStack): string;
begin
 if s.n = 0 then result := '' else
 result := s.a[s.n];
end;

procedure pop(var s: TStack);
begin
 if s.n > 0 then dec(s.n);
end;

var
 s: TStack;
 t: string;
 n, i, j: integer;

procedure showit;
var
 i: integer;
begin
 write('/');
 for i := 1 to s.n do
 write(s.a[i], '/');
 writeln;
end;

begin
 init(s);
 readln(n);
 for i := 1 to n do
 begin
  readln(t);
  if t = 'pwd' then showit else
  begin
   delete(t, 1, 3);
   if t[1] = '/' then
   begin
    init(s);
    while t <> '' do
    begin
     delete(t, 1, 1);
     j := pos('/', t);
     if j < 1 then j := length(t) + 1;
     if copy(t, 1, j - 1) = '..' then pop(s) else
     push(s, copy(t, 1, j - 1));
     delete(t, 1, j - 1);
    end;
   end else
   begin
    t := t + '/';
    while t <> '' do
    begin
     j := pos('/', t);
     if copy(t, 1, j - 1) = '..' then pop(s) else
     push(s, copy(t, 1, j - 1));
     delete(t, 1, j);
    end;
   end;
  end;
 end;
end.