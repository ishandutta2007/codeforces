import math
from functools import reduce
'''input
60
'''
'''input
-60
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


def t(x):
	x = x % 360
	while x >= 180:
		x -= 360
	while x < -180:
		x += 360
	if -45 <= x <= 45:
		return 0
	return 1 + t(x - 90)

print(t(n))