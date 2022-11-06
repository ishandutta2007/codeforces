for _ in range(int(input())):
    a, b, x, y, n = map(int, input().split())
    if a-x+b-y <= n:
        print(x*y)
    else:
        a1 = max(x, a-n)
        b1 = b-(n-(a-a1))
        ans = a1*b1
        t = a
        a = b
        b = t
        t = x
        x = y
        y = t
        a1 = max(x, a-n)
        b1 = b-(n-(a-a1))
        ans = min(ans, a1*b1)
        print(ans)
    # a+b>=x+y+n