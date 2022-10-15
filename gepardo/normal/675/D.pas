{--------------------( alex256 )--------------------\
|    Contest: Codeforces Round 353 (Div. ?)         |
|       Task: D                                     |
|       Date: 16. 05. 2016                          |
\---------------------------------------------------}
program cf353D;

{$mode objfpc}{$H+}{$coperators on}

uses
  SysUtils, Math, FGL;

type
  TVectorInt = specialize TFPGList<Integer>;    

function CmpInt(const A, B: Integer): Integer;
begin
  Result := A - B;
end;

function GetChar: Char;
begin
  Result := #0;
  while Result < ' ' do Read(Result);
end;

const
  Inf = 2147483647;

type
  PTreap = ^TTreap;
  TTreap = record
    X, Y, Index, MinIndex: Integer;
    L, R: PTreap;
  end;

function NewTreap(X, Index: Integer): PTreap;
begin
  New(Result);
  Result^.X := X;
  Result^.Y := Random(1048576);
  Result^.Index := Index;
  Result^.MinIndex := Index;
  Result^.L := nil;
  Result^.R := nil;
end;

function GetIndex(Node: PTreap): Integer;
begin
  if Node = nil
    then Result := Inf
    else Result := Node^.MinIndex;
end;

procedure Update(Node: PTreap);
begin
  if Node = nil then Exit;
  Node^.MinIndex := Min(Node^.Index, Min(GetIndex(Node^.L), GetIndex(Node^.R)));
end;

procedure Split(T: PTreap; X: Integer; var L, R: PTreap);
begin
  if T = nil
    then begin L := nil; R := nil; end
    else if X < T^.X 
           then begin Split(T^.L, X, L, T^.L); R := T; end
           else begin Split(T^.R, X, T^.R, R); L := T; end;
  Update(L); Update(R);
end;

procedure Merge(var T: PTreap; L, R: PTreap);
begin
  if (L = nil) or (R = nil)
    then begin
           if L = nil then T := R else T := L;
         end
    else if L^.Y < R^.Y
           then begin Merge(L^.R, L^.R, R); T := L; end
           else begin Merge(R^.L, L, R^.L); T := R; end;  
  Update(T);
end;
        
procedure Insert(var T: PTreap; It: PTreap);
var T1, T2: PTreap;
begin
  Split(T, It^.X, T1, T2);
  Merge(T, T1, It);
  Merge(T, T, T2);
end;

procedure OutTreap(T: PTreap);
begin
  if T = nil then Exit;
  OutTreap(T^.L);
  Write(T^.X, ' ');
  OutTreap(T^.R);
end;

var
  N, I: Integer;
  A, P: Array [1 .. 1000000] of Integer;
  T1: PTreap;

procedure BuildTree(var Its: PTreap; I: Integer);
var 
  T1, T2, T3: PTreap;
  Q: Integer;
begin
  Split(Its, A[I], T1, T3);
  Split(T1, A[I] - 1, T1, T2);
  if T1 <> nil
    then begin
           Q := T1^.MinIndex;
           P[Q] := I;
           BuildTree(T1, Q);  
         end;
  if T3 <> nil
    then begin
           Q := T3^.MinIndex;
           P[Q] := I;
           BuildTree(T3, Q);
         end; 

  if T2 = nil then while true do;

  Dispose(T2);
  Its := nil;
end;

begin
  Randomize;              
  T1 := nil;
  ReadLn(N);
  for I := 1 to N do
  begin
    Read(A[I]);
    Insert(T1, NewTreap(A[I], I));
  end;
  P[1] := 1;
  BuildTree(T1, 1);
  for I := 2 to N do Write(A[P[I]], ' ');
end.