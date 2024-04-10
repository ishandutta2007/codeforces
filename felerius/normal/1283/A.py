# Contest: Codeforces Round #611 (Div. 3) (https://codeforces.com/contest/1283)
# Problem: A: Minutes Before the New Year (https://codeforces.com/contest/1283/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    h, m = rints()
    print((23 - h) * 60 + (60 - m))