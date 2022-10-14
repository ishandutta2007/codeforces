from math import sqrt

n = int(input()) - 1
r = int((-1 + sqrt(1 + 4 * n * 2)) / 2)
print(n + 1 - (r * (r + 1)) // 2)