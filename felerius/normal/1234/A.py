# Contest: Codeforces Round #590 (Div. 3) (https://codeforces.com/contest/1234)
# Problem: A: Equalize Prices Again (https://codeforces.com/contest/1234/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


q = rint()
for _ in range(q):
    n = rint()
    a = rints()
    print((sum(a) + n - 1) // n)