# Contest: Codeforces Round #570 (Div. 3) (https://codeforces.com/contest/1183)
# Problem: C: Computer Game (https://codeforces.com/contest/1183/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


q = rint()
for _ in range(q):
    k, n, a, b = rints()
    if k - n * b < 1:
        print(-1)
    else:
        k -= n * b
        print(min(n, (k - 1) // (a - b)))