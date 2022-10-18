n,m=map(int,input().split())
ans=0
for i in range(n+1):
 ta=min(i,m//2)
 nn,mm=n-ta,m-ta-ta
 tb=min(nn//2,mm)
 ans=max(ans,ta+tb)
print(ans)