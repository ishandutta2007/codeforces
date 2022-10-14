# Codeforces Beta Round #55
# Problem E -- Shortest Path
n, m, k = map(int, raw_input().split())
v = [[] for i in xrange(n + 1)]
for i in xrange(m):
	x, y = map(int, raw_input().split())
	v[x].append(y)
	v[y].append(x)
f = set()
for i in xrange(k):
	a, b, c = map(int, raw_input().split())
	f.add((a, b, c))
p = [[0] * (n + 1) for i in xrange(n + 1)]
d = [[100000000] * (n + 1) for i in xrange(n + 1)]
d[0][1] = 0
q = [(0, 1)]
while q:
	x, y = q.pop(0)
	for z in v[y]:
		if (x, y, z) not in f and d[x][y] + 1 < d[y][z]:
			p[y][z] = x
			d[y][z] = d[x][y] + 1
			if z == n:
				print d[y][z]
				print 1, 
				def rec(x, y):
					if x != 0:
						rec(p[x][y], x)
						print y, 
				rec(y, z)
				import sys
				sys.exit(0)
			q.append((y, z))
print -1