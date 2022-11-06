# Contest: Codeforces Round #605 (Div. 3) (https://codeforces.com/contest/1272)
# Problem: B: Snow Walking Robot (https://codeforces.com/contest/1272/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


from collections import Counter
t = rint()
for _ in range(t):
    c = Counter(input())
    ud = min(c['D'], c['U'])
    lr = min(c['L'], c['R'])
    if ud == 0 or lr == 0:
        ud = min(1, ud)
        lr = min(1, lr)
    print(2 * ud + 2 * lr)
    print('D' * ud + 'L' * lr + 'U' * ud + 'R' * lr)