a, b = map(int, input().split())

if b - a >= 5:
	print(0)
else:
	ans = 1
	for x in range(a + 1, b + 1):
		ans *= x
		ans %= 10
	print(ans % 10)