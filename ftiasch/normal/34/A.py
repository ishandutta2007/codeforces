# Codeforces Beta Round #34
# Problem A -- Reconnaissance 2
n = int(raw_input())
a = map(int, raw_input().split())
dif = 1000
for i in xrange(n):
	if abs(a[i] - a[(i + 1) % n]) < dif:
		dif, ind = abs(a[i] - a[(i + 1) % n]), i
print ind + 1, (ind + 1) % n + 1