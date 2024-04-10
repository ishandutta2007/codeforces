n,q=map(int,input().split())
p=[-1]+[int(s)-1 for s in input().split()]
o=[0]*n
l=[0]*n
s=[1]*n
v=[1]*n
for i in range(n-1,0,-1):
  s[p[i]] += s[i]
for i in range(1,n):
  l[i]=v[p[i]]
  v[p[i]] += s[i]
  o[l[i]]=i
  v[i]=l[i]+1
res=[0]*q
for i in range(q):
  u,k=map(int,input().split())
  u-=1
  k-=1
  res[i]=str(o[l[u]+k]+1 if k < s[u] else -1)
print('\n'.join(res))