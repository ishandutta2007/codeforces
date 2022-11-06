# Contest: Educational Codeforces Round 81 (Rated for Div. 2) (https://codeforces.com/contest/1295)
# Problem: A: Display The Number (https://codeforces.com/contest/1295/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    n = rint()
    print('7' if n % 2 == 1 else '1', end='')
    n -= 2
    for i in range(n // 2):
        print('1', end='')
    print()