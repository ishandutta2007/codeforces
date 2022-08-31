n = int(input())
a = [int(i) for i in input().split()]
print(max(sum(a[:i]) + (j-i) - sum(a[i:j]) + sum(a[j:]) for i in range(n) for j in range(i+1,n+1)))