import math
from functools import reduce
'''input
1
'''
'''input
2
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

n = int(input())

print(1 if n %2==1 else 2)