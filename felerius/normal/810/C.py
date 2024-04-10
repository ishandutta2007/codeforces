# Contest: Codeforces Round #415 (Div. 2) (https://codeforces.com/contest/810)
# Problem: C: Do you want a date? (https://codeforces.com/contest/810/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


MOD = 10**9 + 7
n = rint()
x = rints()
x.sort()
s = 0
for i in range(1, n):
    s += (x[i] - x[i - 1]) * (pow(2, i, MOD) - 1) * (pow(2, n - i, MOD) - 1) % MOD
    s %= MOD
print(s)