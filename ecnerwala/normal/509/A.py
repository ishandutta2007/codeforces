n = int(input())
n -= 1
res = 1
for i in range(1, 2 * n + 1): res *= i
for i in range(1, n + 1): res //= i * i
print(res)