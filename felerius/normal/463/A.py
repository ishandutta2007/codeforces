# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (11) Caisa and Sugar (Difficulty: 3) (http://codeforces.com/problemset/problem/463/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, s = rints()
sw = -1
for _ in range(n):
    x, y = rints()
    if (x, y) <= (s, 0):
        sw = max(sw, 100 - y if y > 0 else 0)
print(sw)