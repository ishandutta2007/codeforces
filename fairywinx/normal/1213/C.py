q = int(input())
for i in range(q):
    n, m = map(int, input().split())
    m, n = n, m
    m = m // n
    a = [0] * 10
    ans = 0
    for j in range(11, 21):
        a[j % 10] = (n * j) % 10
    k = m // 10
    z = m % 10
    for j in range(10):
        if j == 0:
            ans += max(0, (k - 1) * a[j])
        else:
            ans += k * a[j]
    for j in range(1, z + 1):
        ans += a[j]
    print(ans)
    #5print(a)