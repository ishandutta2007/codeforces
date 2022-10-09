t = int(input())
for u in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    c = []
    for i in range(n):
        s = 0
        for j in b:
            if abs(a[i] - j) == 1:
                c.append(a[i])
                s = 1
                break
        if s == 0:
            b.append(a[i])
    print
    if len(c) == 0:
        print(1)
    else:
        print(2)