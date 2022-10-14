# Codeforces Beta Round #26
# Problem B -- Regular Bracket Sequence
a, b = 0, 0
for c in raw_input():
	if c == '(':
		b += 1
	elif b > 0:
		b -= 1
		a += 2
print a