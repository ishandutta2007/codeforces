# Contest: Codeforces Round #593 (Div. 2) (https://codeforces.com/contest/1236)
# Problem: C: Labs (https://codeforces.com/contest/1236/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
g = [[] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if i % 2 == 0:
            g[j].append(i * n + j + 1)
        else:
            g[n - 1 - j].append(i * n + j + 1)

for gi in g:
    print(' '.join(map(str, gi)))