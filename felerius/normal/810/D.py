# Contest: Codeforces Round #415 (Div. 2) (https://codeforces.com/contest/810)
# Problem: D: Glad to see you! (https://codeforces.com/contest/810/problem/D)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, k = rints()


def ask(x, y):
    print(1, x + 1, y + 1)
    return input() == 'TAK'


def bin_search(l, r):
    while r - l > 1:
        w = r - l
        if w % 2 == 0:
            if ask(l + w // 2 - 1, l + w // 2):
                r = l + w // 2
            else:
                l = l + w // 2
        else:
            if ask(l + w // 2, l + (w + 1) // 2):
                r = l + (w + 1) // 2
            else:
                l = l + (w + 1) // 2
    return l


d = bin_search(0, n)
if d == 0 or d == n - 1:
    left = d == n - 1
elif d > n // 2:
    left = ask(d - (n - 1 - d), n - 1)
else:
    left = not ask(2 * d, 0)

if left:
    d2 = bin_search(0, d)
else:
    d2 = bin_search(d + 1, n)

print(2, d + 1, d2 + 1)