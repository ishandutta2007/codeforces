def has(x, d):
	return str(x).count(str(d)) > 0

t = int(input())
for tc in range(t):
	q, d = map(int, input().split())
	a = map(int, input().split())
	
	dp = [0] * 1005
	dp[0] = 1
	
	for i in range(1, 1002):
		if (has(i, d)):
			for j in range(0, 1003 - i):
				if (dp[j] > 0):
					dp[j + i] = 1
	for x in a:
		if (x > 1000 or dp[x]):
			print("YES")
		else:
			print("NO")