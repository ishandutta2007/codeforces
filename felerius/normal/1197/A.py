t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()), reverse=True)
    print(min(n - 2, a[1] - 1))