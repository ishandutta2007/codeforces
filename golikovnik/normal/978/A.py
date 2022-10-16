n = int(input())
a = [int(x) for x in input().split()]
res = []
for x in a[::-1]:
	if x not in res:
		res.append(x)
print(len(res))
print(*res[::-1])