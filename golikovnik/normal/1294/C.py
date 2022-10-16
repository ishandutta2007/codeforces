t = int(input())
for _ in range(t):
    n = int(input())
    nn = n
    fac = []
    i = 2
    while i * i <= n:
        cnt = 0
        while n % i == 0:
            cnt += 1
            n //= i
        if cnt:
            fac.append((i, cnt))
        i += 1
    if n > 1:
        fac.append((n, 1))
    ok = False
    ans = None
    if len(fac) > 2 or len(fac) == 2 and fac[0][1] + fac[1][1] > 3:
        ok = True
        ans = (fac[0][0], fac[1][0])
    elif len(fac) == 1 and fac[0][1] >= 6:
        ok = True
        ans = (fac[0][0], int(fac[0][0] ** 2))
    if not ok:
        print("NO")
    else:
        print("YES")
        print(ans[0], ans[1], nn // ans[0] // ans[1])