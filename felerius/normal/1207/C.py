# Contest: Educational Codeforces Round 71 (Rated for Div. 2) (https://codeforces.com/contest/1207)
# Problem: C: Gas Pipeline (https://codeforces.com/contest/1207/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


from itertools import groupby
t = rint()
for _ in range(t):
    n, a, b = rints()
    s = input()
    cost = n * a + (n + 1) * b
    for i in range(n + 1):
        left1 = i > 0 and s[i - 1] == '1'
        right1 = i < n and s[i] == '1'
        if left1 or right1:
            cost += b
        if 0 < i < n and left1 != right1:
            cost += a

    g = [sum(1 for _ in v) for k, v in groupby(s) if k == '0']
    for i, gs in enumerate(g[1:-1]):
        if (gs - 1) * b < 2 * a:
            cost += (gs - 1) * b - 2 * a

    print(cost)