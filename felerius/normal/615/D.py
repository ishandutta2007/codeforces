# Contest: 21 - Codeforces Rating >= 2200 (https://a2oj.com/ladder?ID=21)
# Problem: (27) Multipliers (Difficulty: 5) (http://codeforces.com/problemset/problem/615/D)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


from itertools import groupby
from functools import reduce
MOD = 10**9 + 7
n, p = rint(), sorted(rints())
p2 = ((k, sum(1 for _ in g)) for k, g in groupby(p))
res, numdivs = reduce(lambda t1, t2: (pow(t1[0], t2[1] + 1, MOD) * pow(t2[0], (t2[1] * (t2[1] + 1) // 2 * t1[1]) % (MOD - 1), MOD) % MOD, t1[1] * (t2[1] + 1) % (MOD - 1)), p2, (1, 1))
print(res)