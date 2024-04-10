import math
from functools import reduce
'''input
3000
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

t = reduce(lambda a,b: a*b//math.gcd(a,b), range(2, 11), 1)

print(n // t)