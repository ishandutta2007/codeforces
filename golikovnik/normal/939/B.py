n, k = map(int, input().split())
mx = 0
idx = 1
take = 0
for i, x in enumerate(input().split()):
	x = int(x)
	i += 1
	can = n // x * x
	if can > mx:
		mx = can
		idx = i
		take = n // x
print(idx, take)