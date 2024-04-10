N=input()
A=map(int, raw_input().split())
c=[0]*100001
d=[0]*100001
u=[0]*100001
v=[0]*100001
for i in A:
    x=i
    t=0
    if x*2<=100000:
        u[x*2]+=1
        v[x*2]+=1
    while x>0:
        if x%2==1:
            u[x-1]+=t+2
            v[x-1]+=1
        c[x]+=t
        d[x]+=1
        x/=2
        t+=1
    c[x]+=t
    d[x]+=1
for i in xrange(1, 100001):
    if v[i]!=0:
        x=i
        while x<=100000:
            c[x]+=u[i]
            d[x]+=v[i]
            u[i]+=v[i]
            x*=2
print min(j for i, j in zip(d, c) if i==N)