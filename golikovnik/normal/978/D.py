n = int(input())
a = [int(x) for x in input().split()]
if len(a) < 3:
	print(0)
	exit()
INF = 1e10
ans = INF
for a1 in range(a[0] - 1, a[0] + 2):
	for a2 in range(a[1] - 1, a[1] + 2):
		res = abs(a1 - a[0]) + abs(a2 - a[1])
		d = a2 - a1
		cur = a2
		ok = 1
		for x in a[2:]:
			cur += d
			change = abs(x - cur)
			ok &= change < 2
			res += change
		if ok:
			ans = min(ans, res)
print(ans if ans < INF else -1)