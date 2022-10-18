import math

n = int(input())
a = sorted(list(map(int, input().split())))
g = 0
for i in range(len(a) - 1):
  g = math.gcd(g, a[i + 1] - a[i])
print(sum([(a[i + 1] - a[i]) // g - 1 for i in range(len(a) - 1)]))