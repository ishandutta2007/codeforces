# Contest: Codeforces Round #586 (Div. 1 + Div. 2) (https://codeforces.com/contest/1220)
# Problem: A: Cards (https://codeforces.com/contest/1220/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
s = input()
from collections import defaultdict
m = defaultdict(int)
for c in s:
    m[c] += 1
for i in range(m['n']):
    print(1, end=' ')
for i in range(m['z']):
    print(0, end=' ')
print()