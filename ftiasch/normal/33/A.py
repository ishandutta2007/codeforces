# Codeforces Beta Round #33
# What is for dinner?
n, m, k = map(int, raw_input().split())
a = [1000000] * m
for i in xrange(n):
	r, c = map(int, raw_input().split())
	a[r - 1] = min(a[r - 1], c)
s = 0
for i in a:
	s += i
print min(s, k)