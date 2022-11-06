# Contest: Educational Codeforces Round 77 (Rated for Div. 2) (https://codeforces.com/contest/1260)
# Problem: B: Obtain Two Zeroes (https://codeforces.com/contest/1260/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
for _ in range(n):
    a, b = rints()
    if a < b:
        a, b = b, a
    d = a - b
    a -= 2 * d
    b -= d
    print('YES' if a >= 0 and a % 3 == 0 else 'NO')