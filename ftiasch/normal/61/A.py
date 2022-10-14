s = ""
for a, b in zip(raw_input(), raw_input()):
	s += a == b and "0" or "1"
print s