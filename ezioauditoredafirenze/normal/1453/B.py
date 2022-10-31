import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')

for _ in range(int(input())):
	n=int(input())
	a=inputlist()
	pre=0
	result=(int)(1e17)
	for i in range(1,n):
		pre=pre+abs(a[i]-a[i-1])
	for i in range(0,n):
		if i==0:
			result=min(result,pre-abs(a[i+1]-a[i]))
		elif i==n-1:
			result=min(result,pre-abs(a[i]-a[i-1]))
		else:
			result=min(result,pre-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]))
	print(result)