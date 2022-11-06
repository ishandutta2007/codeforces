n = int(input())
a = list(map(int, input().split()))
fi, bi = 0, n - 1
prev = 0
res = []
while fi <= bi:
    f, b = a[fi], a[bi]
    if prev >= f and prev >= b:
        break
    elif f == b:
        cf = 1
        while fi < n - 1 and a[fi + 1] > a[fi]:
            fi += 1
            cf += 1
        cb = 1
        while bi > 0 and a[bi - 1] > a[bi]:
            bi -= 1
            cb += 1
        if cf >= cb:
            res.extend(['L'] * cf)
        else:
            res.extend(['R'] * cb)
        break
    elif f < b:
        if f > prev:
            res.append('L')
            fi += 1
            prev = f
        else:
            res.append('R')
            bi -= 1
            prev = b
    else:
        if b > prev:
            res.append('R')
            bi -= 1
            prev = b
        else:
            res.append('L')
            fi += 1
            prev = f
print(len(res))
for c in res:
    print(c, end='')
print()