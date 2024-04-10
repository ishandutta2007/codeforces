n,k,s=map(int,input().split())
if k<=s<=k*(n-1):
 print("YES")
 l=(s+n-2)//(n-1)
 e=k-l
 r=[]
 for i in range(l):
  v=min(s+1,n)
  s-=v-1
  a=[*range(2,min(e,n-2)+2)]+[v]
  e-=n-2
  if i%2:a=[n+1-x for x in a]
  r.extend(a)
 print(*r)
else:
 print("NO")