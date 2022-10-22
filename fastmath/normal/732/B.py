n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(a)
if n == 1:
    print(0)
    print(a[0])
else:
    ans = 0
    for i in range(1, n):
        if a[i] + b[i - 1] < k:
            ans += k - (a[i] + b[i - 1])
            b[i] = a[i] + (k - (a[i] + b[i - 1]))
    print(ans)
    print(' '.join(map(str, b)))