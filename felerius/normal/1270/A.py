# Contest: Good Bye 2019 (https://codeforces.com/contest/1270)
# Problem: A: Card Game (https://codeforces.com/contest/1270/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    rints()
    print('YES' if max(rints()) > max(rints()) else 'NO')