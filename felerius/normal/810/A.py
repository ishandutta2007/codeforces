# Contest: Codeforces Round #415 (Div. 2) (https://codeforces.com/contest/810)
# Problem: A: Straight <<A>> (https://codeforces.com/contest/810/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, k = rints()
a = rints()
sa = sum(a)
for i in range(20000):
    if (sa + i * k) / (n + i) >= k - 0.5:
        print(i)
        break