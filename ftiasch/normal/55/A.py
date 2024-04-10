# Codeforces Beta Round #51
# Problem A -- Flea travel
n = input()
x = 0
d = {0: True}
for i in xrange(1, n * n + 1):
	x = (x + i) % n
	d[x] = True
if len(d) == n:
	print "YES"
else:
	print "NO"