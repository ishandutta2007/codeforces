def get_path(u, v):
    if u == v:
        return [u]
    pa = [u]
    pb = [v]
    while u != v:
        if u > v:
            u /= 2
            pa.append(u)
        else:
            v /= 2
            pb.append(v)
    return pa + pb[::-1][1:]

from collections import defaultdict

m = defaultdict(int)

for _ in xrange(int(raw_input())):
    a = map(int, raw_input().split())
    p = get_path(a[1], a[2])
    if a[0] == 1:
        for i in xrange(1, len(p)):
            m[(p[i-1], p[i])] += a[3]
            m[(p[i], p[i-1])] += a[3]
    else:
        ans = 0
        for i in xrange(1, len(p)):
            ans += m[(p[i-1], p[i])]
        print ans