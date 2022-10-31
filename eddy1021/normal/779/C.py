R=lambda:list(map(int,input().split()))
n,k=R()
a=R()
b=R()
ans=sum(b)
for i in range(n): a[i]-=b[i]
a=sorted(a)
for i in range(n):
  if i<k or a[i]<0: ans += a[i]
  else: break
print(ans)