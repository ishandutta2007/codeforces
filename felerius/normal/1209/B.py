# Contest: Codeforces Round #584 - Dasha Code Championship - Elimination Round (rated, open for everyone, Div. 1 + Div. 2) (https://codeforces.com/contest/1209)
# Problem: B: Koala and Lights (https://codeforces.com/contest/1209/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
ini = input()
c = [0 for _ in range(200)]
for i in range(n):
    on = ini[i] == '1'
    a, b = rints()
    for j in range(200):
        if j >= b and (j - b) % a == 0:
            on = not on
        c[j] += on

print(max(c))