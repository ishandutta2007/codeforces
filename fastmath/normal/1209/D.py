#counting number of connected components
n, m = map(int, input().split())
g = [[] for i in range(n + 1)]
used = [0] * (n + 1)
for i in range(m):
	u, v = map(int, input().split())
	g[u].append(v)
	g[v].append(u)
ptr = [0] * (n + 1)
path = []
comp = 0
for i in range(1, n + 1):
	if not used[i]:
		comp += 1
		path = [i]
		while len(path) > 0:
			go = -1
			u = path[-1]
			used[u] = 1
			while ptr[u] < len(g[u]):
				v = g[u][ptr[u]]
				ptr[u] += 1
				if not used[v]:
					go = v
					break
				else:
					continue
			if go == -1:
				path.pop()
			else:
				path.append(go)
print(m - (n - comp))