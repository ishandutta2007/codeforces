n = int(input())
a = list(map(int, input().split()))
d1 = dict()
s = 0
for i in range(n):
    d1[a[i]] = d1.get(a[i], 0) + 1
    s += a[i]
p = 0
ans = 0
d2 = dict()
for i in range(n):
    d2[a[i]] = d2.get(a[i], 0) + 1
    p += a[i]
    k1 = d1.get(a[i] - 1, 0) - d2.get(a[i] - 1, 0)
    k2 = d1.get(a[i], 0) - d2.get(a[i], 0)
    k3 = d1.get(a[i] + 1, 0) - d2.get(a[i] + 1, 0)
    k = n - i - 1 - k1 - k2 - k3
    ans += (s - p - (a[i] - 1) * k1 - a[i] * k2 - (a[i] + 1) * k3) - k * a[i]
    
print(ans)