#!/usr/bin/python3

def gcd(a, b):
	if a < 0:
		a = -a
	if b < 0:
		b = -b
	while b > 0:
		a, b = b, a % b
	return a

import random
from math import sqrt
import sys

n = int(input())
to_factor = [n]

idx = 0
for i in range(80):
	if idx >= len(to_factor):
		idx = 0
	if to_factor[idx] == 1:
		del to_factor[idx]
		continue
	m = to_factor[idx]
	x = random.randint(1, m - 1)
	print("sqrt", x ** 2 % n)
	sys.stdout.flush()
	y = int(input())
	if y == -1:
		x = gcd(n, x)
		good = []
		for y in to_factor:
			g = gcd(y, x)
			if g != y and g != 1:
				good.append(g)
				good.append(y // g)
			else:
				good.append(y)
		to_factor = good
		continue
	if (y - x) % m != 0 and (y + x) % m != 0:
		to_factor = to_factor[:idx] + [gcd(y - x, m), gcd(y + x, m)] + to_factor[idx + 1:]
	idx += 1


print("!", len(to_factor), *to_factor, sep=' ')
sys.stdout.flush()