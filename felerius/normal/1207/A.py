# Contest: Educational Codeforces Round 71 (Rated for Div. 2) (https://codeforces.com/contest/1207)
# Problem: A: There Are Two Types Of Burgers (https://codeforces.com/contest/1207/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    b, p, f = rints()
    h, c = rints()
    if h >= c:
        nh = min(b // 2, p)
        prof = h * nh + c * min((b - 2 * nh) // 2, f)
    else:
        nc = min(b // 2, f)
        prof = c * nc + h * min((b - 2 * nc) // 2, p)
    print(prof)