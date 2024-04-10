# Contest: Codeforces Global Round 5 (https://codeforces.com/contest/1237)
# Problem: A: Balanced Rating Changes (https://codeforces.com/contest/1237/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
d = True
for _ in range(n):
    ai = rint()
    if ai % 2 == 0:
        print(ai // 2)
        continue
    if d:
        print(ai // 2)
    else:
        print((ai + 1) // 2)
    d = not d