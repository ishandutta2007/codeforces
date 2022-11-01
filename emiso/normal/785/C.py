n = 0
m = 0

n, m = map(int, raw_input().split())

def f(day):
    nd = day - m
    return nd * (nd + 1) / 2 + m


if n <= m:
    print n

else:
    l = m + 1
    r = 1000000000000000001
    while l < r:
        mid = (l + r) / 2
        if f(mid) >= n:
            r = mid
        else:
            l = mid + 1
    print l