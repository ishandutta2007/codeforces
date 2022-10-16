import re

n = int(input())
s = input()
ans = 0
for occ in re.split("[^x]+", s):
	ans += max(0, len(occ) - 2)
print(ans)