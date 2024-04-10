t = int(input())
for _ in range(t):
	x = int(input())
	res = 0
	while x:
		res += (x & 1)
		x >>= 1
	print(1 << res)