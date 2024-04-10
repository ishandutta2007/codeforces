n = int(input())
print(next(2 * i for i in range(1000000) if (i // 2) * (i // 2 + i % 2) >= n))