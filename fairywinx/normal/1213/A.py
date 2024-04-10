n = int(input())
c = 0
ne = 0
a = list(map(int, input().split()))
for i in range(n):
    if a[i] % 2 == 0:
        c += 1
    else:
        ne += 1
print(min(c, ne))