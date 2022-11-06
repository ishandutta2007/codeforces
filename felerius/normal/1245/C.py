# Contest: Codeforces Round #597 (Div. 2) (https://codeforces.com/contest/1245)
# Problem: C: Constanze's Machine (https://codeforces.com/contest/1245/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


from itertools import groupby
M = 10**9 + 7
s = input()
r = 1
f = [1, 1]
for k, g in groupby(s):
    if k in 'wm':
        print(0)
        exit(0)
    if k not in 'nu':
        continue
    l = sum(1 for _ in g)
    while len(f) <= l:
        f.append((f[-1] + f[-2]) % M)
    r = r * f[l] % M
print(r)