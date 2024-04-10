input()
a=input().split()
ans=0
while len(a)>0:
  at=a[1:].index(a[0])+1
  ans+=at-1
  a=a[1:at]+a[at+1:]
print(ans)