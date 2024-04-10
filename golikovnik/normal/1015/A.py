n, m = map(int, input().split())
cnt = [0] * (m+2)
for _ in range(n):
	l, r = map(int, input().split())
	cnt[l] += 1
	cnt[r+1] -= 1
from itertools import accumulate
nsegments = list(accumulate(cnt))
bad = [x + 1 for x, nn in enumerate(nsegments[1:m+1]) if not nn]
print(len(bad))
print(*bad)