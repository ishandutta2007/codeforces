# Contest: Codeforces Round #605 (Div. 3) (https://codeforces.com/contest/1272)
# Problem: A: Three Friends (https://codeforces.com/contest/1272/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    a, b, c = rints()
    mn = 10**18
    for da in (-1, 0, 1):
        for db in (-1, 0, 1):
            for dc in (-1, 0, 1):
                ai, bi, ci = a + da, b + db, c + dc
                mn = min(mn, abs(ci - ai) + abs(ci - bi) + abs(bi - ai))
    print(mn)