import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')

def gcd(x,y): 
   while(y): 
       x,y=y,x%y 
   return x 

n,m=inputlist()
a=inputlist()
b=inputlist()
a.sort()
result=0
for i in range(n-1):
	result=gcd(result,a[i+1]-a[i])
ans=[]
for i in range(m):
	ans.append(gcd(result,b[i]+a[0]))
printlist(ans)