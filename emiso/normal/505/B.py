n, m = map(int, raw_input().split())

adj = [[[0 for i in xrange(110)] for j in xrange(110)] for k in xrange(110)]
visit = []

def dfs(node, color):
	if visit[node]: return
	visit[node] = 1
	
	for i in xrange(1, n + 1):
		if adj[node][i][color] == 1:
			dfs(i, color)

for i in xrange(m):
	a, b, c = map(int, raw_input().split())
	adj[a][b][c] = 1
	adj[b][a][c] = 1

q = int(raw_input())
for i in xrange(q):
	a, b = map(int, raw_input().split())
	resp = 0
	for j in xrange(1, m + 1):
		visit = [0 for i in xrange(110)]
		dfs(a, j)
		
		if visit[b] == 1:
			resp += 1
	print resp