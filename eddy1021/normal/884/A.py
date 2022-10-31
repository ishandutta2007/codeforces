R=lambda:list(map(int,input().split()))
n,t=R()
a=R()
for i in range(n):
  t-=86400-a[i]
  if t<1:
    print(i+1)
    exit(0)