# Contest: Codeforces Global Round 6 (https://codeforces.com/contest/1266)
# Problem: B: Dice Tower (https://codeforces.com/contest/1266/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


rint()
for i in rints():
    print('YES' if any((i - 21 + j) % 14 == 0 and i - 21 + j >= 0 for j in range(1, 7)) else 'NO')