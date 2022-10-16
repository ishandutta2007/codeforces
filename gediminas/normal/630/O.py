import math
from functools import reduce
'''input
8 8 0 2 8 3 4 5

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

px,py,vx,vy,a,b,c,d=[int(x) for x in input().split()]

vl = math.sqrt(vx**2+vy**2)
vx /= vl
vy /= vl

p = [
	(px + vx * b, py + vy * b),
	(px - vy * a/2, py + vx * a/2),
	(px - vy * c/2, py + vx * c/2),
	(px - vy * c/2 - vx * d, py + vx * c/2 - vy * d),
	(px + vy * c/2 - vx * d, py - vx * c/2 - vy * d),
	(px + vy * c/2, py - vx * c/2),
	(px + vy * a/2, py - vx * a/2),
	]

for t in p:
	print(t[0], t[1])