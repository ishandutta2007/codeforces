# Codeforces Beta Round #39
# Problem E -- Number Table
n, m = map(int, raw_input().split())
if (n + m) % 2 == 1:
	print 0
else:
	k = input()
	f = [map(int, raw_input().split()) for i in xrange(k)]
	if n < m:
		n, m = m, n
		for i in xrange(k):
			f[i][0], f[i][1] = f[i][1], f[i][0]
	p = input()
	cnt, pro = [m] * n, [1] * n
	for i in xrange(k):
		cnt[f[i][0] - 1] -= 1
		pro[f[i][0] - 1] *= f[i][2]
	e = 0
	while cnt[e] < m:
		e += 1
	ans = 1
	for i in xrange(n):
		if i != e:
			if cnt[i] == 0:
				if pro[i] == 1:
					ans = 0
			else:
				ans = (ans * pow(2, cnt[i] - 1, p)) % p
	print ans