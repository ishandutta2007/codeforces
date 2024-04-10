n=int(input())
a=list(map(int, input().split()))
ans=0
for i in range(2, n):
  if a[i-2]==a[i]==1 and a[i-1]==0:
    a[i]=0
    ans+=1
print(ans)