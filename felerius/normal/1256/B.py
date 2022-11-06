# Contest: Codeforces Round #598 (Div. 3) (https://codeforces.com/contest/1256)
# Problem: B: Minimize the Permutation (https://codeforces.com/contest/1256/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


def minimize(p):
    if len(p) <= 1:
        return p
    m = min(p)
    i = p.index(m)
    if i == 0:
        return [m] + minimize(p[1:])
    p = [m] + p[:i] + p[i + 1:]
    return p[:i] + minimize(p[i:])


q = rint()
for _ in range(q):
    n = rint()
    p = rints()
    print(*minimize(p))