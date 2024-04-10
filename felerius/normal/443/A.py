# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (1) Anton and Letters (Difficulty: 1) (http://codeforces.com/problemset/problem/443/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


print(len({c for c in input() if ord('a') <= ord(c) <= ord('z')}))