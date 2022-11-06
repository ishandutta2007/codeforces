# Contest: Codeforces Round #605 (Div. 3) (https://codeforces.com/contest/1272)
# Problem: D: Remove One Element (https://codeforces.com/contest/1272/problem/D)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
a = rints()
rng = []
l = 0
for i in range(1, len(a)):
    if a[i] <= a[i - 1]:
        rng.append((l, i))
        l = i
rng.append((l, n))
mx = max(r - l for l, r in rng)
for i in range(len(rng) - 1):
    l1, r1 = rng[i]
    l2, r2 = rng[i + 1]
    if r1 - l1 == 1 or r2 - l2 == 1:
        continue
    if a[r1 - 2] < a[l2] or a[r1 - 1] < a[l2 + 1]:
        mx = max(mx, r2 - l1 - 1)
print(mx)