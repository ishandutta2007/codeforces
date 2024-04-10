i=lambda:map(int,input().split())
n,h,m=i()
v=[h]*n
for _ in range(m):
 l,r,x=i()
 for a in range(l-1,r):v[a]=min(v[a],x)
print(sum(x*x for x in v))