# Contest: Codeforces Round #582 (Div. 3) (https://codeforces.com/contest/1213)
# Problem: B: Bad Prices (https://codeforces.com/contest/1213/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    n = rint()
    a = rints()
    mi = a[-1]
    bad = 0
    for ai in reversed(a[:-1]):
        if ai > mi:
            bad += 1
        mi = min(mi, ai)
    print(bad)