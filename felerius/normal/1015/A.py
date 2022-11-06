# Contest: Codeforces Round #501 (Div. 3) (https://codeforces.com/contest/1015)
# Problem: A: Points in Segments (https://codeforces.com/contest/1015/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, m = rints()
segs = [rints() for _ in range(n)]
p = []
for i in range(1, m + 1):
    if not any(l <= i <= r for l, r in segs):
        p.append(i)
print(len(p))
print(' '.join(map(str, p)))