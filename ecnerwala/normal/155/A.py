n,a=int(input()),[int(i) for i in input().split()]
print(sum(not min(a[:i]) <= a[i] <= max(a[:i]) for i in range(1,n)))