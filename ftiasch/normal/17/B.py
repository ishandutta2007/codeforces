# Codeforces Beta Round #17
# Problem B -- Hierarchy
import sys

n = input()
q = map(int, raw_input().split())
m = input()
f = [1000001] * n
for i in xrange(m):
	a, b, c = map(int, raw_input().split())
	f[b - 1] = min(f[b - 1], c)
a, c = 0, 0
for x in f:
	if x > 1000000:
		c += 1
		if c > 1:
			print -1
			sys.exit(0)
	else:
		a += x
print a