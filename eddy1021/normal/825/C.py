R=lambda:list(map(int,input().split()))
n,k=R()
a=sorted(R())
b=0
for i in a:
  while i>k+k:
    k+=k
    b+=1
  k=max(k,i)
print(b)