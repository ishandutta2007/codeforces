import re
n,m=list(map(int,input().split()))
s=input()
for _ in range(m):
  l,r,a,b=input().strip().split()
  l,r=int(l),int(r)
  s=s[:l-1]+re.sub(a,b,s[l-1:r])+s[r:]
print(s)