#!/usr/bin/env python3
#! -*- coding: utf-8 -*-
from random import getrandbits

p = []

def get(v):
	global p
	if p[v] == v:
		return v
	p[v] = get(p[v])
	return p[v]

def unite(u, v):
	global p
	u, v = get(u), get(v)
	if u == v:
		return False
	if getrandbits(1):
		u, v = v, u
	p[u] = v
	return True

def main():
	n = int(input())
	global p
	p = list(range(26))
	s = input()
	t = input()
	ans = []
	for i, x in enumerate(zip(s, t)):
		a, b = x
		if unite(ord(a) - ord('a'), ord(b) - ord('a')):
			ans.append((a, b))
	print(len(ans))
	for x in ans:
		print(*x)

if __name__ == '__main__':
	main()