# Contest: Codeforces Round #611 (Div. 3) (https://codeforces.com/contest/1283)
# Problem: B: Candies Division (https://codeforces.com/contest/1283/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    n, k = rints()
    print(min(n, n // k * k + k // 2))