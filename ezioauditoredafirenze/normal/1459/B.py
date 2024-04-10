import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')

n=int(input())
result=0
value=n//2
if n&1:
	result=2*(value+1)*(value+2)
else:
	result=(value+1)**2
print(result)