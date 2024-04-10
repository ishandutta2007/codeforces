R=lambda:list(map(int,input().split()))
n,m=R()
a=0
while m>0 and a==0:
  b=R()[1:]
  d,k=dict(),0
  for i in b:
    if -i in d: k=1
    d[i]=1
  if k==0: a=1
  m-=1
print("NO"if a==0 else"YES")