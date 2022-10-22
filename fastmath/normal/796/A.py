n, m, k = map(int, input().split())
a = list(map(int, input().split()))
ans = 10 ** 10
for i in range(n):
    if a[i] != 0 and a[i] <= k:
        ans = min(ans, abs(i - (m - 1)) * 10)
        
print(ans)