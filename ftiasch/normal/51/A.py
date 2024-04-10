# Codeforces Beta Round #48
# Problem A -- Cheaterius's Problem
n = input()
d = dict()
for i in xrange(n):
	a = raw_input()
	b = raw_input()
	try:
		raw_input()
	except:
		pass
	t = a[0] + a[1] + b[1] + b[0]
	t = min(t, a[1] + b[1] + b[0] + a[0])
	t = min(t, b[1] + b[0] + a[0] + a[1])
	t = min(t, b[0] + a[0] + a[1] + b[1])
	d[t] = 1
print len(d)