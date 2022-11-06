# Contest: Educational Codeforces Round 79 (Rated for Div. 2) (https://codeforces.com/contest/1279)
# Problem: A: New Year Garland (https://codeforces.com/contest/1279/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    c = rints()
    y = True
    for i, j, k in ((0,1,2), (1,0,2), (2,0,1)):
        y = y and c[i] <= c[j] + c[k] + 1
    print('Yes' if y else 'No')