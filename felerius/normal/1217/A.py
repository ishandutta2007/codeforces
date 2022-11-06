# Contest: Educational Codeforces Round 72 (Rated for Div. 2) (https://codeforces.com/contest/1217)
# Problem: A: Creating a Character (https://codeforces.com/contest/1217/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    s, i, e = rints()
    if e == 0:
        print(1 if s > i else 0)
        continue

    e -= max(0, i - s + 1)
    s = max(s, i + 1)
    if e < 0:
        print(0)
        continue

    to_int = min(s - 1 - i, e)
    to_int += (e - to_int) // 2
    print(to_int + 1)