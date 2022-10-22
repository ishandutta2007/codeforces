n = int(input())
a = [0] * n
for i in range(n):
    h, b, c = map(int, input().split())
    a[i] = [max(h, b, c), h + b + c - max(h, b, c) - min(h, b, c), min(h, b, c), i + 1]
a.sort()
best = a[0][2]
ans = a[0][3]
t = 'int'
for i in range(1, n):
    if a[i][2] > best:
        best = a[i][2]
        ans = a[i][3]
        t = 'int'
    if a[i - 1][0] == a[i][0] and a[i - 1][1] == a[i][1] and min(a[i - 1][2] + a[i][2], a[i][1]) > best:
        best = min(a[i - 1][2] + a[i][2], a[i][1])
        ans = [a[i - 1][3], a[i][3]]
        t = 'list'
if t == 'list':
    print(2)
    print(ans[0], ans[1])
else:
    print(1)
    print(ans)