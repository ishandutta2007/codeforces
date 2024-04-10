# Contest: Educational Codeforces Round 77 (Rated for Div. 2) (https://codeforces.com/contest/1260)
# Problem: C: Infinite Fence (https://codeforces.com/contest/1260/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


from math import gcd
t = rint()
for _ in range(t):
    r, b, k = rints()
    if r == b:
        print('OBEY')
        continue
    g = gcd(r, b)
    r //= g
    b //= g
    if r < b:
        r, b = b, r
    print('REBEL' if (r - 2) // b + 1 >= k else 'OBEY')