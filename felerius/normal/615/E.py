# Contest: 21 - Codeforces Rating >= 2200 (https://a2oj.com/ladder?ID=21)
# Problem: (25) Hexagons (Difficulty: 5) (http://codeforces.com/problemset/problem/615/E)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


SIDES = [
    lambda c, v: (1 + 2 * c - v, 2 + 2 * v),
    lambda c, v: (-1 + c - 2 * v, 2 + 2 * c),
    lambda c, v: (-c - 2 - v, 2 * c - 2 * v),
    lambda c, v: (-1 - 2 * c + v, -2 - 2 * v),
    lambda c, v: (1 - c + 2 * v, -2 - 2 * c),
    lambda c, v: (2 + c + v, -2 * c + 2 * v),
]

n = rint()
if n == 0:
    print(0, 0)
    exit(0)
n -= 1
l, h = 0, 10**9
while h - l > 1:
    m = (h + l) // 2
    if 3 * m * (m + 1) > n:
        h = m - 1
    else:
        l = m
c = h if 3 * h * (h + 1) <= n else l
n -= 3 * c * (c + 1)

print(*SIDES[n // (c + 1)](c, n % (c + 1)))