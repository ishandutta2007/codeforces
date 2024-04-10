def solve(n, p, w, d):
    y = 1e18
    if p % w == 0:
        if n - p // w < 0:
            print(-1)
        else:
            print("{} {} {}".format(p // w, 0, n - p // w))
        return
    for i in range(w):
        if (d * i) % w == p % w:
            y = i
            break
    x = (p - y * d) // w
    z = n - x - y
    if z < 0 or x < 0 or y == 1e18:
        print(-1)
    else:
        print("{} {} {}".format(x, y, z))

n, p, w, d = [int(x) for x in input().split()]
solve(n, p, w, d)