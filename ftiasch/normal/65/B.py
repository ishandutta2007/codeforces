# Codeforces Beta Round #60
# Problem B -- Harry Potter and the History of Magic
n = input()
a = [input() for i in xrange(n)]
try:
	p = 1000
	for i in xrange(n):
		x = 2012
		for j in xrange(4):
			for k in xrange(10):
				y = a[i] + (k - a[i] / (10 ** j) % 10) * 10 ** j
				if p <= y <= 2011:
					x = min(x, y)
		if x == 2012:
			raise
		a[i] = p = x
except:
	print "No solution"
else:
	for x in a:
		print x