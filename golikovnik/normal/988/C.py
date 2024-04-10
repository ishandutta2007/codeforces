k = int(input())
can = {}
for i in range(k):
	n = int(input())
	a = [int(x) for x in input().split()]
	s = sum(a)
	for j, x in enumerate(a, 1):
		res = s - x
		if res in can and can[res][0] != i + 1:
			print("YES")
			print(*can[res])
			print(i + 1, j)
			exit()
		else:
			can[res] = (i + 1, j)
print("NO")