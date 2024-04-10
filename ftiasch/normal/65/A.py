# Codeforces Beta Round #60
# Problem A -- Harry Potter and Three Spells
a, b, c, d, e, f = map(int, raw_input().split())
if (a * c * e < b * d * f) or (a == 0 and b * d > 0) or (c == 0 and d > 0):
	print "Ron"
else:
	print "Hermione"