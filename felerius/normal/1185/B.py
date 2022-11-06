# Contest: Codeforces Round #568 (Div. 2) (https://codeforces.com/contest/1185)
# Problem: B: Email from Polycarp (https://codeforces.com/contest/1185/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


from itertools import groupby, zip_longest
n = rint()
for _ in range(n):
    a = input()
    b = input()
    p = True
    for g1, g2 in zip_longest(groupby(a), groupby(b)):
        if g1 is None or g2 is None:
            p = False
            break
        k1, v1 = g1
        k2, v2 = g2
        if k1 != k2 or len(list(v1)) > len(list(v2)):
            p = False
            break
    print('YES' if p else 'NO')