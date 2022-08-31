#!/usr/bin/python

import sys

def vec(a, b):
	return a[0] * b[1] - a[1] * b[0]


x, y = map(int, raw_input().split())

a = [1, 0]
b = [0, 1]

v = [x, y]
ans = ""

while a[0] + b[0] <= x and a[1] + b[1] <= y:
	q = vec(a, v)
	w = abs(vec(b, v))
	if q < w:
		c = (w - 1) // q
		b = [b[0] + c * a[0], b[1] + c * a[1]]
		ans += str(c) + 'A'
	elif q > w:
		c = (q - 1) // w
		a = [a[0] + c * b[0], a[1] + c * b[1]]
		ans += str(c) + 'B'
	else:
		print ans if a[0] + b[0] == x and a[1] + b[1] == y else "Impossible"
		sys.exit(0)

print ans if a[0] + b[0] == x and a[1] + b[1] == y else "Impossible"