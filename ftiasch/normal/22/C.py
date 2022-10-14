# Codeforces Beta Round #22
# Problem C -- System Administrator
n, m, v = map(int, raw_input().split())
if n - 1 <= m and m <= (n - 1) * (n - 2) / 2 + 1:
	l = [i + 1 for i in xrange(n) if i + 1 != v]
	l = l[: -1] + [v] + [l[-1]]
	for i in xrange(n - 1):
		print l[i], l[i + 1]
	m -= n - 1
	i, j = 0, 2
	for k in xrange(m):
		print l[i], l[j]
		j += 1
		if j == n - 1:
			i += 1
			j = i + 2
else:
	print -1