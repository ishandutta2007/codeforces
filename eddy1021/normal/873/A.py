R=lambda:list(map(int,input().split()))
n,k,x=R()
a=list(reversed(R()))
print(sum(x if i < k else a[i] for i in range(n)))