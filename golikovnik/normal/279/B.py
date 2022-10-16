n, t = map(int, input().split())
a = [int(x) for x in input().split()]

def prefixsums(arr):
	from itertools import accumulate
	pref = [0] + list(accumulate(arr))
	return lambda l, r: pref[r] - pref[l-1]

get = prefixsums(a)
r = 1
ans = 0
for l in range(1, n+1):
	while r <= n and get(l, r) <= t:
		r += 1
	ans = max(ans, r - l)
print(ans)