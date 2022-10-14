n, m = list(map(int, input().split()))
result = 1
for i in range(2 * m):
    result = result * (n + i) // (i + 1)
print(result % (10**9 + 7))