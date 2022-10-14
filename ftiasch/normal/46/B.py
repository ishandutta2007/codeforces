# School Personal Contest #2
# Problem B -- T-shirts from Sponsor
kind = ["S", "M", "L", "XL", "XXL"]
size = map(int, raw_input().split())
n = input()
for i in xrange(n):
	c = raw_input()
	for d in [0, 1, -1, 2, -2, 3, -3, 4, -4]:
		temp = kind.index(c) + d
		if 0 <= temp < 5 and size[temp]:
			print kind[temp]
			size[temp] -= 1
			break