# Codeforces Beta Round #39
# Problem D -- Interesting Sequence
b = a = input()
n = 0
while a % 12 == 0:
	a /= 12
	n += 2
if a == 1:
	print "NO"
else:
	a -= 1
	while a % 12 == 0:
		a /= 12
		n += 1
	if a != 1:
		print "NO"
	else:
		print "YES"
		print 1
		print n + 1
		print min(1000, n / 2)
		c = 0
		for i in xrange(n / 2, -1, -1):
			if 12 ** i + 12 ** (n - i) != b:
				print 12 ** i + 12 ** (n - i)
				c += 1
				if c == 1000:
					break