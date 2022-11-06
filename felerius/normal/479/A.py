# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (3) Expression (Difficulty: 2) (http://codeforces.com/problemset/problem/479/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


a = rint()
b = rint()
c = rint()
print(max(
    (a + b) + c,
    (a + b) * c,
    (a * b) + c,
    (a * b) * c,
    a + (b + c),
    a + (b * c),
    a * (b + c),
    a * (b * c),
))