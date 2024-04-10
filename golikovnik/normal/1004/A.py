n, d = map(int, input().split())
a = [int(x) for x in input().split()]

test = set()
for x in a:
	fi = x + d
	se = x - d
	if min(abs(coord - fi) for coord in a) == d:
		test.add(fi)
	if min(abs(coord - se) for coord in a) == d:
		test.add(se)
print(len(test))