n,a=input(),list(map(lambda v:int(v)%2,input().split()))
s=a[:3]
v=sum(s)-max(s)-min(s)
print([i+1 for i in range(int(n))if a[i]!=v][0])