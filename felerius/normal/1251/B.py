# Contest: Educational Codeforces Round 75 (Rated for Div. 2) (https://codeforces.com/contest/1251)
# Problem: B: Binary Palindromes (https://codeforces.com/contest/1251/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


q = rint()
for _ in range(q):
    n = rint()
    s = [input() for _ in range(n)]
    c = [0] * 2
    for si in s:
        for ch in si:
            c[int(ch)] += 1
    o = (c[0] % 2 == 1) or (c[1] % 2 == 1)
    if not o or any(len(si) % 2 == 1 for si in s):
        print(n)
    else:
        print(n - 1)