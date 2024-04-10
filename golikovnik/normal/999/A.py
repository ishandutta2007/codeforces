n, k = map(int, input().split())
a = [int(x) for x in input().split()]

l = min((i for i, x in enumerate(a) if x > k), default=None)
if l is None:
	print(n)
	exit()
r = max(i for i, x in enumerate(a) if x > k)
print(l + n - r - 1)