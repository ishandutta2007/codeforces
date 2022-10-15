{-------------------------------------------------+
|                   ( alex256 )                   |
|-------------------------------------------------+
|            Pascal template v. 1.0.3.            |
+---------+---------------------------------------+
| Contest | CodeForces Round 410 (Div. 2)         |
| Task    | C                                     |
| Date    | 21.04.2017                            |
+---------+---------------------------------------}
program CF410C;

{$IfNDef ONLINE_JUDGE}
  //{$Define LOCAL}
{$EndIf}
//{$Define FILE_IO}
//{$UnDef LOCAL}

{$IfDef LOCAL}
  {$R+}{$I+}{$Q+}{$S+}
{$EndIf}
{$Mode ObjFpc} {$H+} {$B-} {$COperators On} {$Macro On} {$Inline On}
{$ModeSwitch AdvancedRecords} {$Hints Off}

uses
  SysUtils, Classes, Math, DateUtils, GArrayUtils, GDeque, GMap, GPriorityQueue,
  GQueue, GSet, GStack, GUtil, GVector, StrUtils;

const
  Infinity = 1000000000 + 7;
  Infinity64 = 1000000000000000000 + 256;
  Modulo = 1000000000 + 7;
  Luck = '';
  ErrorText = 'Error :(';
{$IfDef FILE_IO}
  TaskName = 'taskname';
  InputFile = TaskName + '.in';
  OutputFile = TaskName + '.out';
{$EndIf}

type
  generic TPair<T1, T2> = record
  private
   class function Compare(const A, B: TPair): Integer; static;
  public
    X: T1;
    Y: T2;
    class function Make(AX: T1; AY: T2): TPair; inline; static;
    class operator<(const A, B: TPair): Boolean; inline;
    class operator<=(const A, B: TPair): Boolean; inline;
    class operator>(const A, B: TPair): Boolean; inline;
    class operator>=(const A, B: TPair): Boolean; inline;
    class operator=(const A, B: TPair): Boolean; inline;
    class operator<>(const A, B: TPair): Boolean; inline;
  end;

class function TPair.Compare(const A, B: TPair): Integer;
begin
  Result := 0;
  if A.X < B.X then Exit(-1);
  if A.X > B.X then Exit(+1);
  if A.Y < B.Y then Exit(-1);
  if A.Y > B.Y then Exit(+1);
end;

class function TPair.Make(AX: T1; AY: T2): TPair; begin Result.X := AX; Result.Y := AY; end;
class operator TPair.<(const A, B: TPair): Boolean; begin Result := Compare(A, B) < 0; end;
class operator TPair.<=(const A, B: TPair): Boolean; begin Result := Compare(A, B) <= 0; end;
class operator TPair.>(const A, B: TPair): Boolean; begin Result := Compare(A, B) > 0; end;
class operator TPair.>=(const A, B: TPair): Boolean; begin Result := Compare(A, B) >= 0; end;
class operator TPair.=(const A, B: TPair): Boolean; begin Result := Compare(A, B) = 0; end;
class operator TPair.<>(const A, B: TPair): Boolean; begin Result := Compare(A, B) <> 0; end;

function ExtGcd(A, B: Int64; var X, Y: Int64): Int64;
var X1, Y1, G: Int64;
begin
  X := 0; Y := 1;
  if A = 0 then Exit(B);
  G := ExtGcd(B mod A, A, X1, Y1);
  X := Y1 - (B div A) * X1;
  Y := X1;
  Exit(G);
end;

function Gcd(A, B: Int64): Int64; begin if B = 0 then Result := A else Result := Gcd(B, A mod B); end;
procedure Error(Text: string = ErrorText); inline; begin WriteLn(Text); Halt(42); end;
function AddMod(A, B: Integer; M: Integer = Modulo): Integer; inline; begin Result := (Int64(A) + B) mod M; end;
function SubMod(A, B: Integer; M: Integer = Modulo): Integer; inline; begin Result := (Int64(A) + M - B) mod M; end;
function MulMod(A, B: Integer; M: Integer = Modulo): Integer; inline; begin Result := (Int64(A) * B) mod M; end;

function DivMod(A, B: Integer; M: Integer = Modulo): Integer; inline;
var X, Y, G: Int64;
begin
  G := ExtGcd(B, M, X, Y);
  if G <> 1 then Error('DivMod error');
  X := (X mod M + M) mod M;
  Result := MulMod(A, X, M);
end;

procedure UMin(var A: Int64; B: Int64); inline; begin A := Min(A, B); end;
procedure UMin(var A: Integer; B: Integer); inline; begin A := Min(A, B); end;
procedure UMax(var A: Int64; B: Int64); inline; begin A := Max(A, B); end;
procedure UMax(var A: Integer; B: Integer); inline; begin A := Max(A, B); end;

function ReadChar: Char; inline; begin Read(Result); end;
function ReadInt: Int64; inline; begin Read(Result); end;
function ReadLine: String; inline; begin ReadLn(Result); end;

function ReadToken: String; inline;
var C: Char;
begin
  Result := ''; C := #0;
  while C <= ' ' do C := ReadChar;
  while not (C <= ' ') do
  begin
    Result += C;
    C := ReadChar;
  end;
end;

type
  TPairIntInt = specialize TPair<Integer, Integer>;
  TPairI64I64 = specialize TPair<Int64, Int64>;

  TLessInt = specialize TLess<Integer>;
  TLessI64 = specialize TLess<Int64>;
  TLessPairIntInt = specialize TLess<TPairIntInt>;
  TLessPairI64I64 = specialize TLess<TPairI64I64>;
  TLessString = specialize TLess<String>;

  TGreaterInt = specialize TGreater<Integer>;
  TGreaterI64 = specialize TGreater<Int64>;
  TGreaterPairIntInt = specialize TGreater<TPairIntInt>;
  TGreaterPairI64I64 = specialize TGreater<TPairI64I64>;
  TGreaterString = specialize TGreater<String>;

  TArrayInt = array of Integer;
  TArrayInt64 = array of Int64;
  TArrayPairIntInt = array of TPairIntInt;
  TArrayPairI64I64 = array of TPairI64I64;
  TArrayString = array of String;

  TVectorInt = specialize TVector<Integer>;
  TVectorI64 = specialize TVector<Int64>;
  TVectorPairIntInt = specialize TVector<TPairIntInt>;
  TVectorPairI64I64 = specialize TVector<TPairI64I64>;
  TVectorString = specialize TVector<String>;

  TVectorVectorInt = specialize TVector<TVectorInt>;
  TVectorVectorPairIntInt = specialize TVector<TVectorPairIntInt>;

  TSetInt = specialize TSet<Integer, TLessInt>;
  TSetI64 = specialize TSet<Int64, TLessI64>;
  TSetPairIntInt = specialize TSet<TPairIntInt, TLessPairIntInt>;
  TSetPairI64I64 = specialize TSet<TPairI64I64, TLessPairI64I64>;

  TQueueInt = specialize TQueue<Integer>;
  TMinPriorityQueuePairIntInt = specialize TPriorityQueue<TPairIntInt, TGreaterPairIntInt>;
  TMinPriorityQueuePairI64I64 = specialize TPriorityQueue<TPairI64I64, TGreaterPairI64I64>;
  TMaxPriorityQueuePairIntInt = specialize TPriorityQueue<TPairIntInt, TLessPairIntInt>;
  TMaxPriorityQueuePairI64I64 = specialize TPriorityQueue<TPairI64I64, TLessPairI64I64>;

// End of template

var
  DP: array [0 .. 199999, 0 .. 1, 0 .. 1] of Integer;

function Main: Integer;
var
  N, I, J, K, G: Integer;
  V: TArrayInt;
begin
  ReadLn(N);
  SetLength(V, N);
  for I := 0 to N-1 do
  begin
    Read(V[I]);
  end;
  G := 0;
  for I := 0 to N-1 do
  begin
    G := Gcd(G, V[I]);
  end;
  if G <> 1 then
  begin
    WriteLn('YES', LineEnding, 0);
    Exit(0);
  end;
  if N = 1 then
  begin
    WriteLn('YES', LineEnding, 1);
    Exit(0);
  end;
  for I := 0 to N-1 do
  begin
    V[I] := V[I] mod 2;
  end;
  for I := 0 to N-2 do
    for J := 0 to 1 do
      for K := 0 to 1 do
      begin
        DP[I, J, K] := Infinity;
      end;
  DP[0, V[0], V[1]] := 0;
  for I := 0 to N-2 do
  begin
    for J := 0 to 3 do
    begin
      UMin(DP[I, 0, 0], Min(DP[I, 0, 0], DP[I, 1, 1]) + 1);
      UMin(DP[I, 1, 1], Min(DP[I, 0, 1], DP[I, 1, 0]) + 1);
    end;
    if I+2 >= N then Continue;
    DP[I+1, 0, V[I+2]] := DP[I, 0, 0];
    DP[I+1, 1, V[I+2]] := DP[I, 0, 1];
  end;
  WriteLn('YES', LineEnding, DP[N-2, 0, 0]);
  Result := 0;
end;

begin
  RandSeed := $42E256;
  {$IfDef FILE_IO}
    AssignFile(Input, InFile); Reset(Input);
    AssignFile(Output, OutFile); Rewite(Output);
  {$EndIf}
  ExitCode := Main;
  {$IfDef FILE_IO}
    CloseFile(Input); CloseFile(Output);
  {$EndIf}
end.