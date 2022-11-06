# Contest: Educational Codeforces Round 71 (Rated for Div. 2) (https://codeforces.com/contest/1207)
# Problem: B: Square Filling (https://codeforces.com/contest/1207/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, m = rints()
a = [rints() for _ in range(n)]
b = [[0] * m for _ in range(n)]
op = []
def pos(x, y):
    return 0 <= x < m - 1 and 0 <= y < n - 1 and a[y][x] and a[y][x + 1] and a[y + 1][x] and a[y + 1][x + 1]

for y in range(n):
    for x in range(m):
        if pos(x, y):
            op.append((x, y))
            for dx, dy in [(0, 0), (1, 0), (1, 1), (0, 1)]:
                b[y + dy][x + dx] = 1
for y in range(n):
    for x in range(m):
        if a[y][x] != b[y][x]:
            print(-1)
            exit(0)

print(len(op))
for x, y in op:
    print(f'{y + 1} {x + 1}')