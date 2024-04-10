# Contest: Codeforces Round #597 (Div. 2) (https://codeforces.com/contest/1245)
# Problem: A: Good ol' Numbers Coloring (https://codeforces.com/contest/1245/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


from math import gcd
t = rint()
for _ in range(t):
    a, b= rints()
    print('Finite' if gcd(a, b) == 1 else 'Infinite')