q = int(input())
for _ in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    pos = True
    for i in range(0, 4 * n, 2):
        if a[i] != a[i + 1]:
            pos = False
            break
    area = a[0] * a[-1]
    if pos:
        for i in range(2, 2 * n, 2):
            pos = pos and a[i] * a[-i - 1] == area
    print('YES' if pos else 'NO')