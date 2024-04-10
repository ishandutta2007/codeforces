n = int(input())
child = {}
for i in range(2, n + 1):
	f = int(input())
	if f not in child:
		child[f] = set()
	child[f].add(i)

for i in range(1, n + 1):
	if i in child:
		t = 0
		for x in child[i]:
			if x not in child:
				t += 1
		if t < 3:
			print("No")
			exit(0)
print("Yes")