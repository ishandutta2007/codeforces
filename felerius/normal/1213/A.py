# Contest: Codeforces Round #582 (Div. 3) (https://codeforces.com/contest/1213)
# Problem: A: Chips Moving (https://codeforces.com/contest/1213/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
x = rints()
mc = 10000
for i in range(n):
    cost = 0
    for j in range(n):
        cost += abs(x[i] - x[j]) % 2
    mc = min(mc, cost)
print(mc)