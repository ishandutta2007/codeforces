# Codeforces Beta Round #29
# Problem A -- Spit Problem
import sys

n = input()
x = list()
d = list()
for i in xrange(n):
	x.append(0)
	d.append(0)
	x[i], d[i] = map(int, raw_input().split())
for i in xrange(n):
	for j in xrange(n):
		if x[i] + d[i] == x[j] and x[j] + d[j] == x[i]:
			print "YES"
			sys.exit(0)
print "NO"