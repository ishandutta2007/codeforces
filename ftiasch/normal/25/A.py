# Codeforces Beta Round #25
# Problem A -- IQ test
n = input()
a = map(int, raw_input().split())
if map(lambda x: x % 2, a).count(0) == 1:
	x = 0
else:
	x = 1
for i in xrange(n):
	if a[i] % 2 == x:
		print i + 1