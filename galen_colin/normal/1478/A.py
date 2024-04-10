t = int(input())
for tc in range(t):
	d = {}
	n = int(input())
	a = map(int, input().split())
	ans = 0
	for x in a:
		if x in d:
			d[x] += 1
		else:
			d[x] = 1
		ans = max(ans, d[x])
	print(ans)