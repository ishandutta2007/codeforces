# Contest: Codeforces Round #568 (Div. 2) (https://codeforces.com/contest/1185)
# Problem: A: Ropewalkers (https://codeforces.com/contest/1185/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


a, b, c, d = rints()
a, b, c = sorted([a, b, c])
print(max(d - (b - a), 0) + max(d - (c - b), 0))