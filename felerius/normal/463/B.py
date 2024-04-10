# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (4) Caisa and Pylons (Difficulty: 2) (http://codeforces.com/problemset/problem/463/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
h = rints()
e = 0
ch = 0
d = 0
for hi in h:
    e += ch - hi
    if e < 0:
        d += -e
        e = 0
    ch = hi
print(d)