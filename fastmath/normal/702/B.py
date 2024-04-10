n = int(input())
a = list(map(int, input().split()))
d = dict()
ans = 0
for i in range(n):
    for j in range(1, 32):
        ans += d.get(2 ** j - a[i], 0)
    d[a[i]] = d.get(a[i], 0) + 1
print(ans)