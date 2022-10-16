n, m = map(int, input().split())
if m == 0:
	print(n, n)
	exit(0)
mn, mx = -1, -1
mn = max(0, n - m - m)

k = 1
while k * (k - 1) // 2 < m:
	k += 1
print(mn, n - k)