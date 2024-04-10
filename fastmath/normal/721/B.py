n, k = map(int, input().split())
a = []
for i in range(n):
    a.append(len(input()))
m = len(input())
a.sort()
i = a.index(m) + 1
j = n - 1
while a[j] != m:
    j -= 1
j += 1
print(i + (i - 1) // k * 5, j + (j - 1) // k * 5)