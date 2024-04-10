l, r = map(int, input().split())

ans = 0

for i in range(42):
	for j in range(42):
		q = 2 ** i * 3 ** j
		if l <= q and q <= r:
			ans += 1

print(ans)