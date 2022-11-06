# Contest: Codeforces Round #581 (Div. 2) (https://codeforces.com/contest/1204)
# Problem: B: Mislove Has Lost an Array (https://codeforces.com/contest/1204/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, l, r = rints()
mi = 2**l - 1 + (n - l)
ma = 2**(r - 1) - 1 + (n - r + 1) * 2**(r - 1)
print(mi, ma)