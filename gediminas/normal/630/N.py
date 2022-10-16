import math
from functools import reduce
'''input
1 30 200
'''

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

a,b,c=[int(x) for x in input().split()]

d = b*b-4*a*c
x1 = (-b + math.sqrt(d))/2 / a
x2 = (-b - math.sqrt(d))/2 / a
print(max(x1,x2))
print(min(x1,x2))