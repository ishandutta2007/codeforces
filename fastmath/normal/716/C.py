n = int(input())
k = 2
for i in range(1, n + 1):
    print(i * (i + 1) * (i + 1) - k)
    k = i