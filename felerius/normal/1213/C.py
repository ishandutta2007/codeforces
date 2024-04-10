# Contest: Codeforces Round #582 (Div. 3) (https://codeforces.com/contest/1213)
# Problem: C: Book Reading (https://codeforces.com/contest/1213/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


from math import gcd
q = rint()
for _ in range(q):
    n, m = rints()
    lcm = 10 * m // gcd(10, m)
    block = 0
    for i in range(lcm // m):
        block += (i + 1) * m % 10
    n_block = n // lcm
    tot = n_block * block
    for i in range(n_block * lcm, n + 1, m):
        tot += i % 10
    print(tot)