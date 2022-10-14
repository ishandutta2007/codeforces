# Codeforces Beta Round #63
# Problem B -- Bets
m, n = map(int, raw_input().split())
t, c = [1001] * m, [0] * m
for i in xrange(n):
	l, r, x, y = map(int, raw_input().split())
	for j in xrange(l - 1, r):
		if x < t[j]:
			t[j], c[j] = x, y
print sum(c)