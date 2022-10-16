n = int(input())
a = [int(i) for i in input().split()]
mn = float("inf")
aa, bb = -1, -1
for i in range(n):
  if abs(a[i] - a[(i + 1) % n]) < mn:
    mn = abs(a[i] - a[(i + 1) % n])
    aa, bb = i + 1, (i + 1) % n + 1
print(aa, bb)