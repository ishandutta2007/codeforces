d, k, a, b, t = map(int, input().split())
if k <= d:
    ans = a * k + (d // k - 1) * min((t + a * k), b * k) + min((d % k) * a + t, (d % k) * b)
    print(ans)
else:
    print(d * a)