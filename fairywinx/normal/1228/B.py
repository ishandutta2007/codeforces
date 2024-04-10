h, w = map(int, input().split())
a = []
for i in range(h):
    a.append([-1] * w)

r = list(map(int, input().split()))
c = list(map(int, input().split()))

for i in range(h):
    if r[i] == w:
        for j in range(w):
            if a[i][j] == 0:
                print(0)
                exit(0)
            a[i][j] = 1
    else:
        for j in range(r[i]):
            if a[i][j] == 0:
                print(0)
                exit(0)
            a[i][j] = 1
        if a[i][r[i]] == 1:
            print(0)
            exit(0)
        a[i][r[i]] = 0

for i in range(w):
    if c[i] == h:
        for j in range(h):
            if a[j][i] == 0:
                print(0)
                exit(0)
            a[j][i] = 1
    else:
        for j in range(c[i]):
            if a[j][i] == 0:
                print(0)
                exit(0)
            a[j][i] = 1
        if a[c[i]][i] == 1:
            print(0)
            exit(0)
        a[c[i]][i] = 0
ans = 1
for i in range(h):
    for j in range(w):
        if a[i][j] == -1:
            ans *= 2
            ans %= 10 ** 9 + 7
print(ans)