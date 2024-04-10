import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')

for _ in range(int(input())):
	n=int(input())
	a=inputlist()
	h=[0]*50
	for i in range(n):
		for j in range(i+1,n):
			h[a[j]-a[i]]+=1
	result=0
	for i in range(50):
		if h[i]>0:
			result+=1
	print(result)