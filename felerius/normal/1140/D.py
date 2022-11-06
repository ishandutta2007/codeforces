n = int(input())
print(sum(i * (i - 1) for i in range(3, n + 1)))