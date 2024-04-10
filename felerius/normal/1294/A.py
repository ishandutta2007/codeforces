# Contest: Codeforces Round #615 (Div. 3) (https://codeforces.com/contest/1294)
# Problem: A: Collecting Coins (https://codeforces.com/contest/1294/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    a,b,c,n = rints()
    a,b,c = sorted([a,b,c])
    mn = c-a + c-b
    print('YES' if mn <= n and (n - mn) % 3 == 0  else 'NO')