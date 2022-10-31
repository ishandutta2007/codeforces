R=lambda:list(map(int,input().split()))
n,k=R()
a=R()
print(len([i for i in range(n)if min(max(a[:i+1]),max(a[i:]))<=k]))