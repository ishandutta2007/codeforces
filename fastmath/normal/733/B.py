n = int(input())
a = [0] * n
l = 0
r = 0
for i in range(n):
    a[i] = list(map(int, input().split()))
    l += a[i][0]
    r += a[i][1]
best = abs(l - r)
ans = 0
for i in range(n):
    new = abs((l - a[i][0] + a[i][1]) - (r - a[i][1] + a[i][0]))
    if new > best:
        best = new
        ans = i + 1
print(ans)