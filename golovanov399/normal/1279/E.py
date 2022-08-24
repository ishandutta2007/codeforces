#!/usr/bin/python3

from math import factorial as fact

N = 55
c = [1]
for i in range(N):
	c.append(fact(i))
dp = [0] * N
dp[0] = 1
for i in range(1, N):
	for j in range(i):
		dp[i] += dp[j] * c[i - j - 1]

def get_kth_cycle(n, k):
	if n == 1:
		return [1]
	ans = [-1] * n
	ans[0] = n - 1
	fin = [i for i in range(n)]
	fin[0] = n - 1
	init = [i for i in range(n)]
	init[n - 1] = 0
	used = [False] * n
	used[n - 1] = True
	for i in range(1, n - 1):
		j = 0
		cur = fact(n - i - 2)
		while True:
			while used[j] or (i < n - 1 and j == init[i]):
				j += 1
			if k > cur:
				k -= cur
				j += 1
			else:
				fin[init[i]] = fin[j]
				init[fin[j]] = init[i]
				ans[i] = j
				used[j] = True
				break
	ans[-1] = init[-1]
	return [x + 1 for x in ans]

def f(n, k):
	if n == 0:
		assert k == 1
		return []
	cl = 1
	while c[cl - 1] * dp[n - cl] < k:
		k -= c[cl - 1] * dp[n - cl]
		cl += 1
	rest = f(n - cl, (k - 1) % dp[n - cl] + 1)
	rest = [x + cl for x in rest]
	k = (k - 1) // dp[n - cl] + 1
	return get_kth_cycle(cl, k) + rest

def solve():
	n, k = map(int, input().split())
	if k > dp[n]:
		print(-1)
		return
	print(*f(n, k))

def main():
	t = int(input())
	while t > 0:
		t -= 1
		solve()

main()