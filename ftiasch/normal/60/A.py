# Codeforces Beta Round #56
# Problem A -- Where Are My Flakes?
import re
n, m = map(int, raw_input().split())
l, r = 1, n
for i in xrange(m):
	d, x = re.findall(r"To the (.*) of (.*)", raw_input())[0]
	if d == "left":
		r = min(r, int(x) - 1)
	else:
		l = max(l, int(x) + 1)
print l <= r and r - l + 1 or -1