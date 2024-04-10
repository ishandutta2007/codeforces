# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (19) Kyoya and Permutation (Difficulty: 4) (http://codeforces.com/problemset/problem/553/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, k = rints()
pos = [0] * (n + 1)
pos[0] = 1
pos[1] = 1
for i in range(2, n + 1):
    pos[i] = pos[i - 1] + pos[i - 2]
perm = list(range(1, n + 1))
i = 0
while i < n - 1:
    if pos[n - i - 1] < k:
        perm[i] += 1
        perm[i + 1] -= 1
        k -= pos[n - i - 1]
        i += 2
    else:
        i += 1
print(' '.join(map(str, perm)))