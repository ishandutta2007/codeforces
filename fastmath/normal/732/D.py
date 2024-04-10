def check(i):
    used = [0] * m
    k = 0
    for i in range(i, -1, -1):
        if d[i] and not used[d[i] - 1]:
            k += a[d[i] - 1]
            used[d[i] - 1] = 1
        elif k:
            k -= 1
    return (not k)
    

n, m = map(int, input().split())
d = list(map(int, input().split()))
a = list(map(int, input().split()))
used = [0] * m
k = m
i = 0
while i < n:
    if d[i] and not used[d[i] - 1]:
        used[d[i] - 1] = 1
        k -= 1
    if not k:
        break
    i += 1
if i == n or not check(n - 1):
    print(-1)
else:
    l = i - 1
    r = n - 1
    while l < r - 1:
        middle = (l + r) // 2
        if check(middle):
            r = middle
        else:
            l = middle
    print(r + 1)