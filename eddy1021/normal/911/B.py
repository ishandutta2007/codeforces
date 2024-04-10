n,a,b=list(map(int,input().split()))
k=1
for i in range(1,min(a,b)+1):
  if a//i+b//i>=n: k=i
print(k)