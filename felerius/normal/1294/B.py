# Contest: Codeforces Round #615 (Div. 3) (https://codeforces.com/contest/1294)
# Problem: B: Collecting Packages (https://codeforces.com/contest/1294/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


def case():
    n = rint()
    p = sorted(tuple(rints()) for _ in range(n))
    maxy = 0
    for (x, y) in p:
        if y < maxy:
            print('NO')
            return
        maxy = y
    cx, cy = 0, 0
    s = ''
    for (x, y) in p:
        while cx < x:
            s += 'R'
            cx += 1
        while cy < y:
            s += 'U'
            cy += 1
    print('YES')
    print(s)


t = rint()
for _ in range(t):
    case()