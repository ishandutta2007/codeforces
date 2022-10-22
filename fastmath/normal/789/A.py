n, k = map(int, input().split())
a = list(map(int, input().split()))

ans = 0
for i in range(n):
    ans += (a[i] - 1) // k + 1
    
print((ans - 1) // 2 + 1)