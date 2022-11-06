# Contest: Educational Codeforces Round 80 (Rated for Div. 2) (https://codeforces.com/contest/1288)
# Problem: C: Two Arrays (https://codeforces.com/contest/1288/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, m = rints()
def f(n):
    return 1 if n <= 1 else n * f(n - 1)
print(f(n + 2 * m - 1) // f(n - 1) // f(2 * m) % (10**9 + 7))