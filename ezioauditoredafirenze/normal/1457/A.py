import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')

for _ in range(int(input())):
	n,m,x,y=inputlist()
	ans=max(max(abs(1-x)+abs(1-y),abs(1-x)+abs(m-y)),max(abs(n-x)+abs(1-y),abs(n-x)+abs(m-y)))
	print(ans)