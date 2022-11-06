# Contest: Educational Codeforces Round 78 (Rated for Div. 2) (https://codeforces.com/contest/1278)
# Problem: A: Shuffle Hashing (https://codeforces.com/contest/1278/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    p = sorted(input())
    h = input()
    b = False
    for i in range(0, len(h) - len(p) + 1):
        if sorted(h[i:i + len(p)]) == p:
            b = True
            break
    print('YES' if b else 'NO')