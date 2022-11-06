# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (9) Inbox (100500) (Difficulty: 2) (http://codeforces.com/problemset/problem/465/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


from itertools import groupby
n = rint()
s = rints()
ops = 0
for k, g in groupby(s):
    if k == 1:
        c = sum(1 for _ in g)
        ops += c + 1
print(max(0, ops - 1))