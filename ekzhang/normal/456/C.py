N = input()
m = 100013
ar = map(int, raw_input().split())
c = [0 for _ in xrange(m)]
for x in ar:
	c[x] += 1

dp = [0 for _ in xrange(m)]
for i in xrange(1, m):
	dp[i] = max([dp[i-1], c[i] * i + dp[i-2]])

print dp[-1]