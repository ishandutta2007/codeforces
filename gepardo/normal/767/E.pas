{-------------------------------------------------+
|                   ( alex256 )                   |
|-------------------------------------------------+
|             Pascal template v. 1.0.             |
+---------+---------------------------------------+
| Contest | CodeForces Round 398 (Div. 2)         |
| Task    | E                                     |
| Date    | 20.04.2017                            |
+---------+---------------------------------------}
program cf398E;

{$IfNDef ONLINE_JUDGE}
  //{$Define LOCAL}
{$EndIf}
//{$Define FILE_IO}
//{$UnDef LOCAL}

{$IfDef LOCAL}
  {$R+}{$I+}{$Q+}{$S+}
{$EndIf}
{$Mode ObjFpc}
{$H+}{$B-}
{$COperators On}{$Macro On}
{$ModeSwitch AdvancedRecords}
{$Hints Off}

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
  if A.X > B.X then Exit(1);
  if A.Y < B.Y then Exit(-1);
  if A.Y > B.Y then Exit(1);
end;

class function TPair.Make(AX: T1; AY: T2): TPair; begin Result.X := AX; Result.Y := AY; end;
class operator TPair.<(const A, B: TPair): Boolean; begin Result := Compare(A, B) < 0; end;
class operator TPair.<=(const A, B: TPair): Boolean; begin Result := Compare(A, B) <= 0; end;
class operator TPair.>(const A, B: TPair): Boolean; begin Result := Compare(A, B) > 0; end;
class operator TPair.>=(const A, B: TPair): Boolean; begin Result := Compare(A, B) >= 0; end;
class operator TPair.=(const A, B: TPair): Boolean; begin Result := Compare(A, B) = 0; end;
class operator TPair.<>(const A, B: TPair): Boolean; begin Result := Compare(A, B) <> 0; end;

function ExtGcd(A, B: Int64; var X, Y: Int64): Int64;
var
  X1, Y1, G: Int64;
begin
  if A = 0 then
  begin
    X := 0; Y := 1;
    Exit(B);
  end;
  G := ExtGcd(B mod A, A, X1, Y1);
  X := Y1 - (B div A) * X1;
  Y := X1;
  Exit(G);
end;

function Gcd(A, B: Int64): Int64; begin if B = 0 then Result := A else Result := Gcd(B, A mod B); end;
procedure Error(Text: string = ErrorText); begin WriteLn(Text); Halt(42); end;
function AddMod(A, B: Integer; M: Integer = Modulo): Integer; begin Result := (Int64(A) + B) mod M; end;
function SubMod(A, B: Integer; M: Integer = Modulo): Integer; begin Result := (Int64(A) + M - B) mod M; end;
function MulMod(A, B: Integer; M: Integer = Modulo): Integer; begin Result := (Int64(A) * B) mod M; end;

function DivMod(A, B: Integer; M: Integer = Modulo): Integer;
var
  X, Y, G: Int64;
begin
  G := ExtGcd(B, M, X, Y);
  if G <> 1 then Error('DivMod error');
  X := (X mod M + M) mod M;
  Result := MulMod(A, X, M);
end;

procedure UMin(var A: Int64; B: Int64); begin A := Min(A, B); end;
procedure UMin(var A: Integer; B: Integer); begin A := Min(A, B); end;
procedure UMax(var A: Int64; B: Int64); begin A := Max(A, B); end;
procedure UMax(var A: Integer; B: Integer); begin A := Max(A, B); end;

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

function Main: Integer;
var
  N, M: Integer;
  C, W: array of Int64;
  I, J: Integer;
  Coins: Int64;
  S: TSetPairI64I64;
  Take: array of Boolean;
  MustCoin: Integer;
  CanGet: Integer;
  CurSat: Int64;
  Res: Int64;
  MinEl: TPairI64I64;
  BanknoteCnt, CoinCnt: Integer;
begin
  ReadLn(N, M);
  SetLength(C, N);
  SetLength(W, N);
  for I := 0 to N-1 do Read(C[I]); ReadLn;
  for I := 0 to N-1 do Read(W[I]); ReadLn;
  S := TSetPairI64I64.Create;
  try
    SetLength(Take, N);
    Coins := M;
    Res := 0;
    for I := 0 to N-1 do
    begin
      MustCoin := C[I] mod 100;
      CanGet := 100 - MustCoin;
      CurSat := CanGet * W[I];
      if MustCoin = 0 then
      begin
        Take[I] := True;
        Continue;
      end;
      if (MustCoin > Coins) and (not S.IsEmpty) and
         (S.Min.Data.X < CurSat) then
      begin
        MinEl := S.Min.Data;
        Coins += 100;
        Res += MinEl.X;
        Take[MinEl.Y] := False;
        S.Delete(MinEl);
      end;
      if MustCoin <= Coins then
      begin
        Coins -= MustCoin;
        Take[I] := True;
        S.Insert(TPairI64I64.Make(CurSat, I));
      end
      else
      begin
        Take[I] := False;
        Coins += CanGet;
        Res += CurSat;
      end;
    end;
    WriteLn(Res);
    for I := 0 to N-1 do
    begin
      if Take[I] then
      begin
        BanknoteCnt := C[I] div 100;
        CoinCnt := C[I] mod 100;
      end
      else
      begin
        BanknoteCnt := C[I] div 100 + 1;
        CoinCnt := 0;
      end;
      WriteLn(BanknoteCnt, ' ', CoinCnt);
    end;
  finally
    FreeAndNil(S);
  end;
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