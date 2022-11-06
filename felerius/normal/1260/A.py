# Contest: Educational Codeforces Round 77 (Rated for Div. 2) (https://codeforces.com/contest/1260)
# Problem: A: Heating (https://codeforces.com/contest/1260/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
for _ in range(n):
    c, s = rints()
    if c >= s:
        print(s)
        continue
    s1 = s // c
    s2 = s1 + 1
    print(s2**2 * (s % c) + s1**2 * (c - s % c))