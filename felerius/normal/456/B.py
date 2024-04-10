# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (15) Fedya and Maths (Difficulty: 3) (http://codeforces.com/problemset/problem/456/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
print((1 + pow(2, n, 5) + pow(3, n, 5) + pow(4, n, 5)) % 5)