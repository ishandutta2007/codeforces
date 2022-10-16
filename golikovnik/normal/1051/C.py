n = int(input())
a = [int(x) for x in input().split()]

from collections import Counter
cnt = Counter(a)

solo = set()
big = set()
for x, v in cnt.items():
	if v == 1:
		solo.add(x)
	if v >= 3:
		big.add(x)
if len(solo) % 2 == 0:
	print("YES")
	cur = 0
	for x in a:
		if x in solo:
			print("AB"[cur], end="")
			cur ^= 1
		else:
			print("A", end="")
	print()
else:
	if not big:
		print("NO")
	else:
		print("YES")
		did_big = 0
		cur = 0
		for x in a:
			if x in solo:
				print("AB"[cur], end="")
				cur ^= 1
			elif x in big and not did_big:
				print("B", end="")
				did_big = 1
			else:
				print("A", end="")
		print()