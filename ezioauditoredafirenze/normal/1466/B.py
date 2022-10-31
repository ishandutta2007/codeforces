import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')

for _ in range(int(input())):
	n=int(input())
	a=inputlist()
	result=0
	freq=[0]*(2*n+5)
	for i in range(n):
		if freq[a[i]]>0:
			freq[a[i]+1]+=1
		else:
			freq[a[i]]+=1
	for i in range(2*n+5):
		if freq[i]>0:
			result+=1
	print(result)