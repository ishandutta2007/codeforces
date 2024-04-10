# Contest: Educational Codeforces Round 81 (Rated for Div. 2) (https://codeforces.com/contest/1295)
# Problem: B: Infinite Prefixes (https://codeforces.com/contest/1295/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    n, x = rints()
    s = input()
    bal, min_bal, max_bal = 0, 0, 0
    from collections import defaultdict
    counts = defaultdict(int)
    for c in s:
        bal += 1 if c == '0' else -1
        min_bal = min(min_bal, bal)
        max_bal = max(max_bal, bal)
        counts[bal] += 1
    bal_range = max_bal - min_bal
    if bal == 0:
        if min_bal <= x <= max_bal:
            print(-1)
        else:
            print(0)
    else:
        b = 0
        d = 1 if x == 0 else 0
        for c in s:
            b += 1 if c == '0' else -1
            d += (x - b) % bal == 0 and (x - b) // bal >= 0
        print(d)