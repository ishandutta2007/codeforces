import math
from functools import reduce
'''input
2 5 3

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

def V(a, h):
	return a*h/3

print(V(a*a*math.sqrt(3)/4, a*math.sqrt(2/3)) + V(b*b,b / math.sqrt(2)) + c*c*c*(5+math.sqrt(5))/24)