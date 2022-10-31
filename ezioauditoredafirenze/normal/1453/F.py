import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')
up = (int)(1e18)

for _ in range(int(input())):
	n=int(input())
	a=inputlist()
	dp=[[0]*(n+1) for i in range(n+1)]
	for i in range(n-1,-1,-1):
		for j in range(i,-1,-1):
			dp[j][i]=dp[j+1][i]
			if a[j]>i-j:
				dp[j][i]=dp[j][i]+1
	_dp=[[up]*(n+1) for i in range(n+1)]
	_dp[n-1][n]=0
	for i in range(n-1,-1,-1):
		idx=i+a[i]
		while idx>i:
			_dp[i][idx]=min(_dp[i][idx+1],dp[i+1][idx-1]+_dp[idx][i+a[i]+1])
			idx=idx-1
	print(_dp[0][1])