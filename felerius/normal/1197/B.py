n = int(input())
a = list(map(int, input().split()))
idx = list(range(n))
idx.sort(key=lambda i: a[i], reverse=True)
imin = imax = idx[0]
for i in idx[1:]:
    if i == imin - 1 or i == imax + 1:
        imin = min(imin, i)
        imax = max(imax, i)
    else:
        print('NO')
        exit(0)
print('YES')