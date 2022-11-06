n = int(input())
a = list(map(int, input().split()))
fi, bi = 0, n - 1
prev = 0
res = []
while fi <= bi:
    f, b = a[fi], a[bi]
    if prev >= f and prev >= b:
        break
    elif f <= b:
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