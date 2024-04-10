from math import *
from collections import *

s = raw_input()

cnt = defaultdict(int)

for i in s:
	cnt[i] += 1

ans = cnt['B']
ans = min(ans, cnt['u']/2)
ans = min(ans, cnt['l'])
ans = min(ans, cnt['b'])
ans = min(ans, cnt['a']/2)
ans = min(ans, cnt['s'])
ans = min(ans, cnt['r'])

print ans