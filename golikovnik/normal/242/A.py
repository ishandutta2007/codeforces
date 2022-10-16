x, y, a, b = map(int, input().split())
results = []
for i in range(a, x + 1):
	for j in range(b, y + 1):
		if i <= j:
			continue
		results.append((i, j))
print(len(results))
results.sort()
for a, b in results:
	print(a, b)