n, w = map(int, input().split())
a = [int(x) for x in input().split()]
l, r = 0, w
cur = 0
for x in a:
	cur += x
	if cur < 0:
		l = max(l, abs(cur))
	elif cur > 0:
		r = min(r, w - cur)
print(max(0, r - l + 1))