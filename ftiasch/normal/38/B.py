# School Personal Contest #1
# Problem B -- Chess
r, k = map(lambda s: (ord(s[0]) - ord('a'), ord(s[1]) - ord('1')), [raw_input(), raw_input()])
c = 0
for x in xrange(8):
	for y in xrange(8):
		if x == r[0] or y == r[1]:
			continue
		if x == k[0] and y == k[1]:
			continue
		tmp = [abs(x - r[0]), abs(y - r[1])]
		if 1 in tmp and 2 in tmp:
			continue
		tmp = [abs(x - k[0]), abs(y - k[1])]
		if 1 in tmp and 2 in tmp:
			continue
		c += 1
print c