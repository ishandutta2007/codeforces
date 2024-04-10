# Contest: Educational Codeforces Round 80 (Rated for Div. 2) (https://codeforces.com/contest/1288)
# Problem: A: Deadline (https://codeforces.com/contest/1288/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
from math import sqrt, ceil
for _ in range(t):
    n, d = rints()
    ds = int(sqrt(d))
    pos = False
    for i in range(-10, 10):
        if ds + i < 0 or ds + i > n:
            continue
        pos = pos or ds + i + int(ceil(d / (ds + i + 1))) <= n
    print('Yes' if pos else 'No')