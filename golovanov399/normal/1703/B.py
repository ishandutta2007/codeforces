#!/usr/bin/env python3

t = int(input())
for _ in range(t):
	input()
	s = input().strip()
	print(len(s) + len(set(s)))