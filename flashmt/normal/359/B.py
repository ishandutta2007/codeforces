n, k = input().split()
n = int(n)
k = int(k)
for i in range(n):
    if (i >= k):
        print(i * 2 + 2, i * 2 + 1, end = ' ')
    else:
        print(i * 2 + 1, i * 2 + 2, end = ' ')