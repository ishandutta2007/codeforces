# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (21) Sea and Islands (Difficulty: 4) (http://codeforces.com/problemset/problem/544/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, k = rints()
m = [['S'] * n for _ in range(n)]
for y in range(n):
    for x in range(y % 2, n, 2):
        if k > 0:
            m[y][x] = 'L'
            k -= 1
if k > 0:
    print('NO')
else:
    print('YES')
    for r in m:
        print(''.join(r))