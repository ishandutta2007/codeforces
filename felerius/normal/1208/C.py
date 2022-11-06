# Contest: Manthan, Codefest 19 (open for everyone, rated, Div. 1 + Div. 2) (https://codeforces.com/contest/1208)
# Problem: C: Magic Grid (https://codeforces.com/contest/1208/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
m = [[0] * n for _ in range(n)]
for y in range(0, n, 2):
    for x in range(0, n, 2):
        b = y * n + 2 * x
        m[y][x] = b
        m[y][x + 1] = b + 1
        m[y + 1][x] = b + 3
        m[y + 1][x + 1] = b + 2

for row in m:
    print(' '.join(map(str, row)))