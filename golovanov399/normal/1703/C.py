#!/usr/bin/env python3

t = int(input())
for _ in range(t):
	n = int(input())
	ans = list(map(int, input().split()))
	for i in range(n):
		s = input().split()[1]
		for c in s:
			ans[i] += 1 if c == 'D' else -1
	for i in range(n):
		ans[i] %= 10
	print(*ans)