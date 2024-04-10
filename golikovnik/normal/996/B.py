n = int(input())
a = [int(x) for x in input().split()]

mn = 1e10
ans = -1

for i, x in enumerate(a):
	t = i + (x - i + n - 1) // n * n
	if t < mn:
		mn = t
		ans = i + 1

if ans > 0:
	print(ans)
else:
	assert False