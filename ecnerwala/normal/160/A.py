n=int(input())
a=sorted(map(int,input().split()))
print(n+1-min(i for i in range(n+1) if sum(a[:i])>=sum(a[i:])))