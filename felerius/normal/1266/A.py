# Contest: Codeforces Global Round 6 (https://codeforces.com/contest/1266)
# Problem: A: Competitive Programmer (https://codeforces.com/contest/1266/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
from collections import Counter
for _ in range(t):
    c = Counter(input())
    if c['0'] == 0:
        print('cyan')
        continue
    c['0'] -= 1
    s = sum(i * c[str(i)] for i in range(10))
    two = any(c[str(i)] > 0 for i in (0, 2, 4, 6, 8))
    print('red' if s % 3 == 0 and two else 'cyan')