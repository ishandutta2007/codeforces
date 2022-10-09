def f(k):
    global ans
    used[k] = 1
    ans += 1
    if used[a[k] - 1] == 1:
        return
    c[a[k] - 1] = c[k]
    f(a[k] - 1)

q = int(input())
for u in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    c = [0] * n
    b = []
    j = 0
    used = [0] * n
    for i in range(n):
        ans = 0
        if used[i] == 0:
            c[i] = j
            j += 1
            f(i)
            b.append(ans)
    for i in range(n):
        print(b[c[i]], end = ' ')
    print()