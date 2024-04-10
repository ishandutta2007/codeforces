# Contest: Good Bye 2019 (https://codeforces.com/contest/1270)
# Problem: C: Make Good (https://codeforces.com/contest/1270/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


from functools import reduce
from operator import xor
t = rint()
for _ in range(t):
    n = rint()
    a = rints()
    s = sum(a)
    x = reduce(xor, a)
    print(2)
    print(x, s + x)