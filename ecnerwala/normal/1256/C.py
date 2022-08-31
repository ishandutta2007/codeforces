i=lambda:[*map(int,input().split())]
n,m,d=i()
c=i()
n-=sum(c)
d-=1
m+=1
if m*d>=n:
    print("YES")
    a=[]
    for v in range(m):
        if v:a+=[v]*c[v-1]
        a+=[0]*(n//m+(v<n%m))
    print(*a)
else:
    print("NO")