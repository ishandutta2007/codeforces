# Contest: Codeforces Round #593 (Div. 2) (https://codeforces.com/contest/1236)
# Problem: A: Stones (https://codeforces.com/contest/1236/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    a, b, c, = rints()
    mx = 0
    for ta in range(0, min(a, b // 2) + 1):
        mx = max(mx, 3 * ta + 3 * min(b - 2 * ta, c // 2))
    print(mx)