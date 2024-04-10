# Contest: Educational Codeforces Round 74 (Rated for Div. 2) (https://codeforces.com/contest/1238)
# Problem: A: Prime Subtraction (https://codeforces.com/contest/1238/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    x, y = rints()
    print('YES' if x - y > 1 else 'NO')