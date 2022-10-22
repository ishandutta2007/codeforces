n = int(input())
x = -1
y = -1
a = []
s = [0] * (2 * n + 2)
for i in range(n):
    a.append(list(map(int, input().split())))
for i in range(n):
    for j in range(n):
        if not a[i][j]:
            x = i
            y = j
            break
for i in range(n):
    s[i] = sum(a[i])
for i in range(n, 2 * n):
    sm = 0
    for j in range(n):
        sm += a[j][i - n]
    s[i] = sm
for i in range(n):
    s[2 * n] += a[i][i]
    s[2 * n + 1] += a[i][n - i - 1]
    
check = True
if x == y and x + y == n - 1:
    if not(s[x] == s[n + y] == s[2 * n] == s[2 * n + 1]):
        print(-1)
        check = False
elif x == y:
    if not(s[x] == s[n + y] == s[2 * n]):
        print(-1)
        check = False
elif x + y == n - 1:
    if not(s[x] == s[n + y] == s[2 * n + 1]):
        print(-1)
        check = False
else:
    if not(s[x] == s[n + y]):
        print(-1)
        check = False
if check:
    for i in range(2 * n + 2):
        if not check:
            break
        for j in range(2 * n + 2):
            if i != x and i != n + y and j != n + y and j != x and not(x == y and i == 2 * n) and not(x == y and j == 2 * n) and not(x + y == n - 1 and i == 2 * n + 1) and not(x + y == n - 1 and j == 2 * n + 1) and s[i] != s[j]:
                check = False
                print(-1)
                break
if check:
    if n == 1:
        print(1)
    elif x:
        if s[0] <= s[x]:
            print(-1)
        else:
            print(s[0] - s[x])
    else:
        if s[1] <= s[x]:
            print(-1)
        else:
            print(s[1] - s[x])