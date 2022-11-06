n = int(input())
a = [i if i < 0 else (-i - 1) for i in map(int, input().split())]
if n % 2 == 0:
    print(' '.join(map(str, a)))
else:
    imin = 0
    for i in range(1, n):
        if a[i] < a[imin]:
            imin = i
    a[imin] = -a[imin] - 1
    print(' '.join(map(str, a)))