# Contest: Codeforces Global Round 6 (https://codeforces.com/contest/1266)
# Problem: C: Diverse Matrix (https://codeforces.com/contest/1266/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


r, c = rints()
if r == c == 1:
    print(0)
    exit()
if c == 1:
    for y in range(r):
        print(y + 2)
    exit()
for y in range(r):
    print(*((y + 1) * (x + r + 1) for x in range(c)))