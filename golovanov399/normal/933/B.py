#!/usr/bin/python2

p, k = map(int, raw_input().split())

a = []
while p > 0:
	a.append(p % k)
	p //= k

i = 0
while i < len(a):
	if a[i] == k:
		a[i] = 0
		if i + 1 == len(a):
			a.append(0)
		a[i + 1] += 1
	elif i % 2 == 1 and a[i] != 0:
		a[i] = k - a[i]
		if i + 1 == len(a):
			a.append(0)
		a[i + 1] += 1
	i += 1

print len(a)
print " ".join(map(str, a))