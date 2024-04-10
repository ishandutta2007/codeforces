n, m = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
for i in range(m):
    s = 0
    l, r = map(int, input().split())
    for j in range(l - 1, r):
        s += a[j]
    if s >= 0:
        ans += s
print(ans)