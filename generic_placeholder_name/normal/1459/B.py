n = int(input())
print([(n // 2 + 1) ** 2, ((n + 2) ** 2) // 2][n & 1])