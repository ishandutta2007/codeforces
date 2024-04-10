def read_input():
	return map(int, input().split())

a, b, c, n = read_input()
only_a, only_b = a - c, b - c
if only_a < 0 or only_b < 0:
	print(-1)
	exit()
total = only_b + only_a + c
if total >= n:
	print(-1)
	exit()
print(n - only_a - only_b - c)