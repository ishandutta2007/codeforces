input()
s = input()

from collections import Counter
cnt = Counter(s)
for k, v in cnt.items():
	print(k * v, end='')
print()