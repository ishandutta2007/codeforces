t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if k > n:
        print('NO')
        continue
    if n % 2 == k % 2:
        print('YES')
        print(*([1] * (k - 1) + [n - k + 1]))
        continue
    if n % 2 == 0 and n >= 2 * k:
        print('YES')
        print(*([2] * (k - 1) + [n - 2 * k + 2]))
        continue
    print('NO')