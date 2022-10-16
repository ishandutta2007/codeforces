n = int(input())
a = [None] * n
for i in range(n):
	a[i] = tuple(map(int, input().split()))
ans = 0
for i, x in enumerate(a):
	ok = 0
	for j, y in enumerate(a):
		if i == j:
			continue
		if y[1] == x[0]:
			ok = 1
	ans += (ok ^ 1)
print(ans)