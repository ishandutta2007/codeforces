# Contest: Educational Codeforces Round 68 (Rated for Div. 2) (https://codeforces.com/contest/1194)
# Problem: B: Yet Another Crosses Problem (https://codeforces.com/contest/1194/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    n, m = rints()
    s = [input() for _ in range(n)]
    rows = [0] * n
    cols = [0] * m
    for i, si in enumerate(s):
        for j, c in enumerate(si):
            if c == '*':
                rows[i] += 1
                cols[j] += 1
    res = n + m
    for i, vr in enumerate(rows):
        for j, vc in enumerate(cols):
            res = min(res, n - vc + m - vr - (1 if s[i][j] == '.' else 0))
    print(res)