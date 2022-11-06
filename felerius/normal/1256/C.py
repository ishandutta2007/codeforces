# Contest: Codeforces Round #598 (Div. 3) (https://codeforces.com/contest/1256)
# Problem: C: Platforms Jumping (https://codeforces.com/contest/1256/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, m, d = rints()
c = rints()
sumc = sum(c)
if d == 1:
    if sumc < n:
        print('NO')
        exit(0)
    print('YES')
    for i, ci in enumerate(c):
        for _ in range(ci):
            print(i + 1, end=' ')
    print()
    exit(0)

water = n - sumc
if water / (d - 1) > m + 1:
    print('NO')
    exit(0)

print('YES')
for i, ci in enumerate(c):
    if water:
        for _ in range(min(water, d - 1)):
            print(0, end=' ')
        water -= min(water, d - 1)
    for _ in range(ci):
        print(i + 1, end=' ')
if water:
    for _ in range(water):
        print(0, end=' ')
print()