from fractions import Fraction

VERT = object()
n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]
d = {}
for i, p in enumerate(points):
    x1, y1 = p
    for x2, y2 in points[i + 1:]:
        if x1 < x2:
            f = Fraction(y2 - y1, x2 - x1)
        elif x1 > x2:
            f = Fraction(y1 - y2, x1 - x2)
        else:
            f = VERT
        if f == VERT:
            x_inter = x1
        else:
            x_inter = y1 - x1 * f
        # if f == VERT:
        #     print(f'VERT {x_inter}')
        # else:
        #     print(f'{f.numerator}/{f.denominator} {x_inter}')
        if f == VERT:
            key = VERT
            value = x_inter
        else:
            key = f.numerator / f.denominator
            value = x_inter.numerator / x_inter.denominator
        if key in d:
            d[key].add(x_inter)
        else:
            d[key] = {x_inter}

total = sum(len(s) for s in d.values())
total_inter = 0
for s in d.values():
    total_inter += len(s) * (total - len(s))

print(total_inter // 2)