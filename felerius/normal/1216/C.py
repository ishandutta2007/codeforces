# Contest: Codeforces Round #587 (Div. 3) (https://codeforces.com/contest/1216)
# Problem: C: White Sheet (https://codeforces.com/contest/1216/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


def in_rect(x, y, r):
    x1, y1, x2, y2 = r
    return x1 <= x <= x2 and y1 <= y <= y2


w = rints()
b1 = rints()
b2 = rints()
xvals = sorted([w[0], w[2], b1[0], b1[2], b2[0], b2[2]])
yvals = sorted([w[1], w[3], b1[1], b1[3], b2[1], b2[3]])
for x in xvals:
    for y in yvals:
        if in_rect(x + 0.5, y + 0.5, w) and not in_rect(x + 0.5, y + 0.5, b1) and not in_rect(x + 0.5, y + 0.5, b2):
            print('YES')
            exit(0)
print('NO')