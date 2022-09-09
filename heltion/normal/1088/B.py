n, k = [int(x) for x in input().split()]
a = sorted([int(x) for x in input().split()])
c, p = 0, 0
for x in a:
	if x > p:
		c += 1
		print(x - p)
		p = x
		if c == k:
			break
while c < k:
	print(0)
	c += 1