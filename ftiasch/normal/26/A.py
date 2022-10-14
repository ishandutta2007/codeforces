# Codeforces Beta Round #26
# Problem A -- Almost Prime
n = int(raw_input())
h = [0] * (n + 1)
for i in xrange(2, n + 1):
	if not h[i]:
		for j in xrange(i, n + 1, i):
			h[j] += 1
s = 0
for i in xrange(2, n + 1):
	if h[i] == 2:
		s += 1
print s