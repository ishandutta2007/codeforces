# Contest: Codeforces Global Round 4 (https://codeforces.com/contest/1178)
# Problem: C: Tiles (https://codeforces.com/contest/1178/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


w, h = rints()
print(pow(2, w + h, 998244353))