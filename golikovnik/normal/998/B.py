n, b = map(int, input().split())
a = [int(x) for x in input().split()]

can = []

count = [0, 0]
for i, x in enumerate(a[:-1]):
	count[x & 1] += 1
	if count[0] == count[1]:
		can.append(abs(x - a[i+1]))

ans = 0
for x in sorted(can):
	if x > b: break
	ans += 1
	b -= x
print(ans)