# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (13) Set of Strings (Difficulty: 3) (http://codeforces.com/problemset/problem/544/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, m = rints()
for y in range(n):
    print(''.join('-' if c == '-' else ('B' if (x + y) % 2 == 0 else 'W') for x, c in enumerate(input())))