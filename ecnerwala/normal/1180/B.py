input()
a=[min(v,-1-v)for v in map(int,input().split())]
if len(a)&1:i=a.index(min(a));a[i]=-1-a[i]
print(*a)