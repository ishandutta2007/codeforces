from sys import stdin

input = stdin.readline

n, m = map(int, input().split())
vs = [int(i) for i in input().split()]
ans = 0.0
for _ in range(m):
	a, b, c = map(int, input().split())
	if c:
		ans = max(ans, (vs[a-1] + vs[b-1]) / c)
print(ans)