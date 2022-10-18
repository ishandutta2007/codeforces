r=lambda:map(int,input().split())
n,m=r()
a=list(r())
mx=-1
mxi=0
while n:
 n-=1
 z=(a[n]+m-1)//m
 if z>mx:
  mx=z
  mxi=n+1
print(mxi)