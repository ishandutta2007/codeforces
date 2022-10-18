f=lambda:map(int,input().split())
n,k=f()
a=sorted(list(f()))
ans=0
i=n-1
while i>=0:
 ans+=2*a[i]-2
 i-=k
print(ans)