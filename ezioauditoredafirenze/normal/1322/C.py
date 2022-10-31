import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from math import gcd
 
t=int(input())
for tests in range(t):
    n,m=map(int,input().split())
    C=list(map(int,input().split()))
    X=[[] for i in range(n+1)]
    for k in range(m):
        x,y=map(int,input().split())
        X[y].append(x)
    A=dict()
    for i in range(n):
        if tuple(sorted(X[i+1])) in A:
            A[tuple(sorted(X[i+1]))]+=C[i]
        else:
            A[tuple(sorted(X[i+1]))]=C[i]
    ans=0
    for g in A:
        if g==tuple():
            continue
        ans=gcd(ans,A[g])
    print(ans)
    _=input()