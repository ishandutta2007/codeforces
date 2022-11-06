# Contest: Codeforces Round #587 (Div. 3) (https://codeforces.com/contest/1216)
# Problem: D: Swords (https://codeforces.com/contest/1216/problem/D)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


import functools, math
n = rint()
a = rints()
m = max(a)
d = [m - ai for ai in a if ai < m]
g = functools.reduce(math.gcd, d)
print(sum(d) // g, g)