n = int(input())
a = list(map(int, input().split()))
b = [0 for i in range(n)]
for i in range(n):
    b[a[i] - 1] = i + 1
for c in b:
    print(c, end = ' ')