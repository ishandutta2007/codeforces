# Codeforces Beta Round #17
# Problem A -- Noldbach problem
n, k = map(int, raw_input().split())
prime = []
for i in xrange(2, n + 1):
	j = 2
	while j * j <= i and i % j != 0:
		j += 1
	if i % j != 0:
		prime.append(i)
for p in prime:
	for q, r in zip(prime[1:], prime[:-1]):
		if q + r + 1 == p:
			
			k -= 1
			break
print k <= 0 and "YES" or "NO"