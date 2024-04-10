n, k = map(int, input().split())

if k > n**2:
    print(-1)
    exit(0)

m = []
for _ in range(n):
    m.append([0] * n)

for y in range(n):
    if k < 2:
        break
    for x in range(y, n):
        if k < 2:
            break
        if x == y:
            m[y][x] = 1
            k -= 1
        else:
            m[y][x] = 1
            m[x][y] = 1
            k -= 2

if k == 1:
    for i in range(n):
        if m[i][i] == 0:
            m[i][i] = 1
            break


for y in range(n):
    for x in range(n):
        print(m[y][x], end=' ')
    print()