#!/usr/bin/env python3

t = int(input())
for _ in range(t):
	s = input().strip()
	print("Yes" if s.lower() == "yes" else "No")