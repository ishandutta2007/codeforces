def check(t):
    return (m + t) >= n - (t - 1) * t // 2

    
n, m = map(int, input().split())

if (m >= n):
    print(n)
else:
    l = 0
    r = 10 ** 30
    while l < r - 1:
        mid = (l + r) // 2
        if check(mid):
            r = mid
        else:
            l = mid
    
    print(m + r)