# Codeforces Beta Round #31
# Problem A --  Worms Evolution
import sys

n = input()
a = map(int, raw_input().split())
for i in xrange(n):
	for j in xrange(n):
		for k in xrange(n):
			if j <> k and a[i] == a[j] + a[k]:
				print i + 1, j + 1, k + 1
				sys.exit(0)
print -1