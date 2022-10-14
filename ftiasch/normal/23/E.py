# Codeforces Beta Round #23
# Problem E -- Tree
n = int(raw_input())
g = [[] for i in range(n)]
for i in xrange(n - 1):
	u, v = map(int, raw_input().split())
	g[u - 1].append(v - 1)
	g[v - 1].append(u - 1)

f = [1] * n
h = [1] * n
o = [[] for i in xrange(n)]

def dfs(p, u):
	global g, f, h, o
	for v in g[u]:
		if v != p:
			dfs(u, v)
			h[u] *= f[v]
			o[u].append(v)
	l = o[u]
	for i in xrange(len(l)):
		k = i
		for j in xrange(i + 1, len(l)):
			if h[l[j]] * f[l[k]] > h[l[k]] * f[l[j]]:
				k = j
		l[i], l[k] = l[k], l[i]
	f[u] = h[u]
	temp = h[u]
	for i in xrange(len(l)):
		temp = temp / f[l[i]] * h[l[i]]
		f[u] = max(f[u], temp * (i + 2))
	for i in o[u]:
		l, temp = o[i], h[i]
		for j in xrange(len(l)):
			temp = temp / f[l[j]] * h[l[j]]
			f[u] = max(f[u], h[u] / f[i] * temp * (j + 3))
dfs(-1, 0)
print f[0]