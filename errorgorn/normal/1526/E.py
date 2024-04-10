MOD=998244353

n,k=map(int,input().split())
arr=list(map(int,input().split()))

pos=[0]*(n+1)

for i in range(n):
	pos[arr[i]]=i
pos[n]=-1

cnt=0

for i in range(n-1):
	if (pos[arr[i]+1]>pos[arr[i+1]+1]): cnt+=1

#k-cnt+n-1 choose n
num,denom=1,1

for i in range(n):
	num=num*(k-cnt+n-1-i)%MOD
	denom=denom*(i+1)%MOD

print(num*pow(denom,MOD-2,MOD)%MOD)