n = int(input())
a = list(sorted(map(int, input().split())))

maxsize = 0
j = 0
for i in range(len(a)):
    while a[i] - a[j] > 5:
        j += 1
    maxsize = max(maxsize, i - j + 1)

print(maxsize)