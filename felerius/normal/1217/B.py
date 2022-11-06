# Contest: Educational Codeforces Round 72 (Rated for Div. 2) (https://codeforces.com/contest/1217)
# Problem: B: Zmei Gorynich (https://codeforces.com/contest/1217/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    n, x = rints()
    max_red = 0
    max_blow = 0
    for __ in range(n):
        d, h = rints()
        max_red = max(max_red, d - h)
        max_blow = max(max_blow, d)
    if max_red == 0 and max_blow < x:
        print(-1)
        continue
    red_health = max(0, x - max_blow)
    print(1 if max_blow >= x else (red_health + max_red - 1) // max_red + 1)