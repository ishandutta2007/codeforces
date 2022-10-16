n = int(input())
s = n * (n + 1) // 2
print(s & 1)
x = s // 2
res = set()
for i in range(n, 0, -1):
	if i <= x:
		x -= i
		res.add(i)
		if not x:
			break
print(len(res), *res)