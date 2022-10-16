from math import sqrt
n = int(input())
sz = n // 2
bins = [int(i) for i in input().split()]
sqr = 0
zeros = 0
for cnt in bins:
    if sqrt(cnt).is_integer():
        sqr += 1
    if cnt == 0:
        zeros += 1
if sqr >= sz:
    left = sqr - sz
    nonzeros = sqr - zeros
    first = max(0, left - nonzeros)
    print(left + first)
else:
    add = [0] * (n - sqr)
    i = 0
    for cnt in bins:
        root = sqrt(cnt)
        if not root.is_integer():
            lower = int(root) ** 2
            upper = (int(root) + 1) ** 2
            add[i] = min(cnt - lower, upper - cnt)
            i += 1
    add.sort()
    print(sum(add[:sz - sqr]))