# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (12) Laptops (Difficulty: 3) (http://codeforces.com/problemset/problem/456/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


k = rint()
q = input()
p = [1000] * 26
for i, c in enumerate(q):
    p[ord(c) - ord('a')] = min(i, p[ord(c) - ord('a')])
pv = [i for i in p if i < 1000]
if len(pv) < k:
    print('NO')
    exit(0)
pv = sorted(pv)
print('YES')
for i in range(k):
    if i == k - 1:
        print(q[pv[i]:])
    else:
        print(q[pv[i]:pv[i + 1]])