program qwe;

{$MODE DELPHI}

const maxN = 122222;

procedure swap(var x: integer; var y: integer);
var
	z: integer;
begin
	z := x;
	x := y;
	y := z;
end;

function gcd(x: integer; y: integer): integer;
begin
	while y > 0 do
	begin
		x := x mod y;
		swap(x, y);
	end;
	result := x
end;

var
	a: array[1..maxN] of integer;
	n, i, g, mn, mx: integer;

begin
	readln(n);
	for i := 1 to n do
		read(a[i]);

	g := 0;
	for i := 2 to n do
		g := gcd(g, abs(a[i] - a[1]));

	mn := a[1];
	mx := a[1];
	for i := 2 to n do
	begin
		if a[i] > mx then mx := a[i];
		if a[i] < mn then mn := a[i];
	end;
	
	writeln((mx - mn) div g - n + 1);
end.