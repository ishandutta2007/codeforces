n, k = map(int, input().split())
a = list(map(int, input().split()))

s = 0
for i in range(n):
    l = max(0, i - k + 1)
    r = min(i, n - k)
    
    s += a[i] * (r - l + 1)
        
    
print(s / (n - k + 1))