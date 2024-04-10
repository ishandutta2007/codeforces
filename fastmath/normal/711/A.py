n = int(input())
a = []
x = -1
y = -1
for i in range(n):
    a.append(input())
    if a[-1][0] == a[-1][1] == 'O':
        x = [i, 0]
        y = [i, 1]
    if a[-1][3] == a[-1][4] == 'O':
        x = [i, 3]
        y = [i, 4]
if x == -1:
    print('NO')
else:
    print('YES')
    a[x[0]] = a[x[0]][:x[1]] + '+' + a[x[0]][x[1] + 1:]
    a[y[0]] = a[y[0]][:y[1]] + '+' + a[y[0]][y[1] + 1:]
    for i in range(n):
        print(a[i])