n, k = map(int, input().split())
if k == 1:
    print(n)
else:
    res = 1
    while res * 2 <= n:
        res <<= 1
    print(res * 2 - 1)