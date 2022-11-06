# Contest: Codeforces Round #570 (Div. 3) (https://codeforces.com/contest/1183)
# Problem: B: Equalize Prices (https://codeforces.com/contest/1183/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


q = rint()
for _ in range(q):
    n, k = rints()
    a = rints()
    mi = min(a)
    ma = max(a)
    if ma - mi > 2 * k:
        print(-1)
    else:
        print(mi + k)