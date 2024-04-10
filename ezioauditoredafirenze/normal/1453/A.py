import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')
N = 10002

for _ in range(int(input())):
	n,m=inputlist()
	a=inputlist()
	b=inputlist()
	result=0
	h=N*[0]
	for x in a:
		h[x]=h[x]+1
	for x in b:
		if h[x]==1:
			result = result+1
	print(result)