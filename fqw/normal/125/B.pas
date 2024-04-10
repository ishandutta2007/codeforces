var
	s, s0: ansistring;
	dep, i: longint;
begin
	readln(s);
	dep := 0;
	while s <> '' do
	begin
		i := pos('>', s);
		s0 := copy(s, 1, i);
		delete(s, 1, i);
		if (s0[2] = '/') then
			dec(dep, 2);
		for i := 1 to dep do
			write(' ');
		writeln(s0);
		if (s0[2] <> '/') then
			inc(dep, 2);
	end;
end.