t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    h = list(map(int, input().split()))
    pos = True
    for i in range(n - 1):
        m += min(h[i] + k - h[i + 1], h[i])
        pos = pos and m >= 0
    print('YES' if pos else 'NO')