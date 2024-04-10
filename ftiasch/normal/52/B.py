# Codeforces Testing Round #1
# Problem B -- Right Triangles
n, m = map(int, raw_input().split())
g = [raw_input() for i in xrange(n)]
row, col = [0] * n, [0] * m
for i in xrange(n):
	for j in xrange(m):
		if g[i][j] == '*':
			row[i] += 1
			col[j] += 1
cnt = 0
for i in xrange(n):
	for j in xrange(m):
		if g[i][j] == '*':
			cnt += (row[i] - 1) * (col[j] - 1)
print cnt