def bp1(time):
    return (time // t) * k


def bp2(time):
    return (time // t) * k  + (max(time - d, 0) // t) * k


n, t, k, d = map(int, input().split())

l = 0
r = 10 ** 9
while l < r - 1:
    m = (l + r) // 2
    if bp1(m) >= n:
        r = m
    else:
        l = m
ans1 = r


l = 0
r = 10 ** 9
while l < r - 1:
    m = (l + r) // 2
    if bp2(m) >= n:
        r = m
    else:
        l = m
ans2 = r

if ans2 < ans1:
    print('YES')
else:
    print('NO')