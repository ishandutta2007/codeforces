# Contest: Educational Codeforces Round 80 (Rated for Div. 2) (https://codeforces.com/contest/1288)
# Problem: B: Yet Another Meme Problem (https://codeforces.com/contest/1288/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    a, b = rints()
    c = 0
    for i in range(1, 20):
        if 10**i - 1 <= b:
            c += 1
    print(c * a)