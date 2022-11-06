# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (7) DZY Loves Hash (Difficulty: 2) (http://codeforces.com/problemset/problem/447/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


p, n = rints()
b = [False] * p
for i in range(n):
    xi = rint()
    if b[xi % p]:
        print(i + 1)
        exit(0)
    b[xi % p] = True
print(-1)