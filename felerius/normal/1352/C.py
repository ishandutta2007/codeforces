t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    k -= 1
    print((k // (n  - 1)) * n + (k % (n - 1)) + 1)