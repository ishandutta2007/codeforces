# Contest: Codeforces Round #598 (Div. 3) (https://codeforces.com/contest/1256)
# Problem: A: Payment Without Change (https://codeforces.com/contest/1256/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


q = rint()
for _ in range(q):
    a, b, n, s = rints()
    x, y = divmod(s, n)
    if x > a:
        y += n * (x - a)
        x = a
    print('YES' if y <= b else 'NO')