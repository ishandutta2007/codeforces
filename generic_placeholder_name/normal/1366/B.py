for _ in range(int(input())):
    n, x, m = list(map(int, input().split()))
    mn, mx = x, x
    for i in range(m):
        l, r = list(map(int, input().split()))
        if r >= mn and l <= mx:
            mn, mx = min(mn, l), max(mx, r)
    print(mx - mn + 1)