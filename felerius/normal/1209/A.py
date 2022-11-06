# Contest: Codeforces Round #584 - Dasha Code Championship - Elimination Round (rated, open for everyone, Div. 1 + Div. 2) (https://codeforces.com/contest/1209)
# Problem: A: Paint the Numbers (https://codeforces.com/contest/1209/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
a = sorted(rints())
c = 0
while a:
    c += 1
    mi = min(a)
    newa = []
    for ai in a:
        if ai % mi:
            newa.append(ai)
    a = newa

print(c)