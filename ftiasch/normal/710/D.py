from math import ceil, floor, gcd
from fractions import Fraction as Frac
from typing import Tuple


def ext_gcd(a: int, b: int, c: int) -> Tuple[int, int]:
    # a * x - b * y = c
    if b == 0:
        return (c // a, 0)
    #   b * x - (a - a // b * b) * y
    # = a * (-y) + b * (x + a // b * y)
    x, y = ext_gcd(b, a % b, c)
    return -y, -(x + a // b * y)


def solve(a1: int, b1: int, a2: int, b2: int, l: int, r: int) -> int:
    g = gcd(a1, a2)
    # a1 * x + b1 = a2 * y + b2
    if (b1 - b2) % g != 0:
        return 0
    x0, y0 = ext_gcd(a1, a2, b2 - b1)
    # x = x0 + k * a2 / g >= 0
    # y = y0 + k * a1 / g
    # a1 * (x0 + k * a2 // g) + b1 >= l
    min_k = max(
        ceil(Frac(-x0, a2 // g)),
        ceil(Frac(-y0, a1 // g)),
        ceil(Frac(l - b1 - a1 * x0, a1 * a2 // g))
    )
    max_k = floor(
        Frac(Frac(r - b1 - a1 * x0, a1 * a2 // g))
    )
    return max(max_k - min_k + 1, 0)


l = map(int, input().split())
result = solve(*l)
print(result)