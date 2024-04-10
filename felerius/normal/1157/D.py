n, k = map(int, input().split())

base = k * (k + 1) // 2
if n < base:
    print('NO')
    exit(0)

l = [i + 1 + (n - base) // k for i in range(k)]
rem = (n - base) % k
if (n - base) // k == 0 and rem != 0 and rem == k - 1:
    if k in (2, 3):
        print('NO')
        exit(0)
    else:
        l[-1] += 2
        for i in range(rem - 2):
            l[-i - 2] += 1
else:
    for i in range(rem):
        l[-i - 1] += 1
print('YES')
print(' '.join(map(str, l)))