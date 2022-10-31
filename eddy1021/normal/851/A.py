n,k,t=list(map(int,input().split()))
print(t-max(0,t-k)if t<=n else max(0, n-t+k))