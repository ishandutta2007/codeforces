# Codeforces Beta Round #47
# Problem B -- Choosing Symbol Pairs
h = {}
for c in raw_input():
	try:
		temp = h[c]
	except KeyError:
		temp = 0
	h[c] = temp + 1
a = 0
for k, v in h.items():
	a += v * v
print a