R=lambda:list(map(int,input().split()))
n,k=R()
a=R()
c=[0 for i in range(n+1)]
while 1>0:
  if a[0]>a[1]: a[0],a[1]=a[1],a[0]
  a=a[1:]+a[:1]
  c[a[0]]+=1
  if a[0]==n or c[a[0]]>=k:
    print(a[0])
    break