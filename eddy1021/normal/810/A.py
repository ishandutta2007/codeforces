R=lambda:list(map(int,input().split()))
n,k=R()
a=R()
s=sum(a)
l=len(a)
b=0
while (s+l//2)//l<k:
  s+=k
  l+=1
  b+=1
print(b)