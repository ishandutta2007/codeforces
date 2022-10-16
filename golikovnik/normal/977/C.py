from collections import Counter

n, k = map(int, input().split())
a = [int(i) for i in input().split()]
if not k:
	if min(a) > 1:
		print(1)
	else:
		print(-1)
	exit(0)
cnt = Counter(a)
already = 0
for num, v in sorted(cnt.items()):
	already += v
	if already == k:
		print(num)
		exit(0)
print(-1)