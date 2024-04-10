t = int(input())
for u in range(t):
    n, k, d = map(int, input().split())
    a = list(map(int, input().split()))
    c = [0] * k
    for i in range(d):
        c[a[i] - 1] += 1
    ans = 0
    mn_ans= 0
    for i in range(k):
        if c[i] != 0:
            ans += 1
    mn_ans = ans
    for i in range(d, n):
        c[a[i - d] - 1] -= 1
        c[a[i] - 1] += 1
        #print(c, a[i - d], a[i], c[a[i - d] - 1], c[a[i] - 1])
        if a[i - d] - 1 != a[i] - 1:
            if c[a[i - d] - 1] == 0:
                ans -= 1
            if c[a[i] - 1] == 1:
                ans += 1
        mn_ans = min(ans, mn_ans)
    print(mn_ans)