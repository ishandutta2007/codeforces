# Contest: Educational Codeforces Round 76 (Rated for Div. 2) (https://codeforces.com/contest/1257)
# Problem: B: Magic Stick (https://codeforces.com/contest/1257/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    x, y = rints()
    if x == 1:
        r = y == 1
    elif x == 2 or x == 3:
        r = y <= 3
    else:
        r = True
    print('YES' if r else 'NO')