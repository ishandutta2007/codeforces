# Contest: Educational Codeforces Round 22 (https://codeforces.com/contest/813)
# Problem: A: The Contest (https://codeforces.com/contest/813/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
s = sum(rints())
m = rint()
for _ in range(m):
    l, r = rints()
    if s <= r:
        print(max(l, s))
        exit(0)
print(-1)