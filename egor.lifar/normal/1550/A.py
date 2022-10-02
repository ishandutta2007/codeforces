t = int(input())
for i in range(t):
	s = int(input())
	cur = 1
	a = 1
	b = 1
	while cur < s:
		a += 2
		cur += a
		b += 1
	print(b)