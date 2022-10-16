import math
from functools import reduce
'''input
12
'''

n = int(input())

def F(n):
	t = 1
	for i in range(n):
		t *= n - i
	return t

def C(n, k):
	t = 1
	for i in range(k):
		t *= n - i
	for i in range(k):
		t //= i + 1
	return t

def lcm(a,b):
	return a *b//math.gcd(a,b)

def t(xs, lc, cof):
	if len(xs) == 0:
		return cof * (n // lc)
	x = xs[0]
	xs = xs[1:]
	return t(xs, lc, cof) + t(xs, lcm(lc, x), -cof)


print(t(list(range(2,11)), 1, 1))