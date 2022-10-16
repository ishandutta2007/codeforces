n = int(input())
mini = float("inf")
maxi = float("-inf")
segs = []
for _ in range(n):
	a, b = map(int, input().split())
	mini = min(a, mini)
	maxi = max(b, maxi)
	segs.append((a, b))
res = (mini, maxi)
if res in segs:
	print(segs.index(res) + 1)
else:
	print(-1)