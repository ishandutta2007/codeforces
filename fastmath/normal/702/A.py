n = int(input())
a = list(map(int, input().split())) + [10 ** 9]
F = [0] * (n + 1)
for i in range(n):
    if a[i] > a[i - 1]:
        F[i] = F[i - 1] + 1
    else:
        F[i] = 1
print(max(F))