# Contest: Educational Codeforces Round 76 (Rated for Div. 2) (https://codeforces.com/contest/1257)
# Problem: A: Two Rival Students (https://codeforces.com/contest/1257/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    n, x, a, b = rints()
    a -= 1
    b -= 1
    a, b = sorted((a, b))
    l = min(a, x)
    a -= l
    x -= l
    r = min(n - 1 - b, x)
    b += r
    print(b - a)