n=int(input())
a=list(map(int,input().split()))
b=[0 for i in range(n+1)]
c,k=0,0
for i in a:
  if b[i]: c -= 1
  else: c += 1
  b[i]=1
  k=max(k,c)
print(k)