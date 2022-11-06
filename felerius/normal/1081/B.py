# Contest: Avito Cool Challenge 2018 (https://codeforces.com/contest/1081)
# Problem: B: Farewell Party (https://codeforces.com/contest/1081/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
m = [[] for _ in range(n)]
for i, ai in enumerate(rints()):
    m[n - 1 - ai].append(i)
res = [0] * n
c = 1
for i in range(n):
    if not m[i]:
        continue
    if len(m[i]) % (i + 1):
        print('Impossible')
        exit(0)
    for j, idx in enumerate(m[i]):
        res[idx] = c + j // (i + 1)
    c += len(m[i]) // (i + 1)
print('Possible')
print(*res)