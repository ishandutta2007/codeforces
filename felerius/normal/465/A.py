# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (8) inc ARG (Difficulty: 2) (http://codeforces.com/problemset/problem/465/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
bits = input()
bits = bits[::-1]
before = int(bits, 2)
after = (before + 1) % 2**n
print(bin(before ^ after).count('1', 2))