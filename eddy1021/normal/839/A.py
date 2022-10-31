R=lambda:list(map(int,input().split()))
n,k=R()
a=R()
s=0
for i in range(n):
  s+=a[i]
  d=min(s,8)
  s-=d
  k-=d
  if k<=0:
    print(i+1)
    break
else:
  print(-1)