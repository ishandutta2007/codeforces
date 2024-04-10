n, m = map(int, raw_input().split())
a = list(map(int, raw_input().split()))

a = sorted(a)

ans = 111111111
for i in range(m - n + 1):
    ans = min(ans, a[i + n - 1] - a[i])

print ans