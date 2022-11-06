# Contest: Educational Codeforces Round 68 (Rated for Div. 2) (https://codeforces.com/contest/1194)
# Problem: A: Remove a Progression (https://codeforces.com/contest/1194/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    n, x = rints()
    print(2 * x)