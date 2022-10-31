n,m=list(map(int,input().split()))
c=0
for a in range(1000):
  for b in range(1000):
    if a*a+b==n and a+b*b==m:
      c+=1
print(c)